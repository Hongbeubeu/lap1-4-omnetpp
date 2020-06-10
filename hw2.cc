
#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include "hw2_m.h"

using namespace omnetpp;

class Hw2 : public cSimpleModule
{
    private:
        int isInited;
        int start;
        int finish;
        int count;
        int size;
        int neighbors[8];
        int distances[8];
        int gates[8];
        int checked[8];
        int checkedGates[8];
        double xpos;
        double ypos;
    protected:
        virtual HwMsg2 *generateMessage();
        virtual void forwardMessage(HwMsg2 *msg);
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Hw2);

void Hw2::initialize()
{
    start = par("start");
    finish = par("finish");
    isInited = 0;
    if (getIndex() == start) {
        xpos = par("xpos");
        ypos = par("ypos");
        size = gateSize("out");
        count = size;
        for(int i = 0; i < size; i++){
            neighbors[i] = 0;
            distances[i] = 0;
            gates[i] = 0;
            checked[i] = 0;
            checkedGates[i] = 0;
        }
        isInited = 1;
        char msgname[20];
        sprintf(msgname, "node-%d", getIndex());
        EV <<getFullName()<<"\n";
        HwMsg2 *msg = generateMessage();
        msg->setPreGate(size - count);
        send(msg, "out", size - count);
    }
}

void Hw2::handleMessage(cMessage *msg)
{
    if(isInited == 0){
        xpos = par("xpos");
        ypos = par("ypos");
        size = gateSize("out");
        count = size;
        for(int i = 0; i < size; i++){
            neighbors[i] = 0;
            distances[i] = 0;
            gates[i] = 0;
            checked[i] = 0;
            checkedGates[i] = 0;
        }
        isInited = 1;
    }
    for(int i = 0; i < gateSize("in"); i++){
       cGate *inGate = gate("in", i);
       cChannel *channel = inGate->getIncomingTransmissionChannel();
       EV <<"source Gate "<< i << " = "<<channel->getSourceGate()->getFullPath()<<"\n";
    }
    HwMsg2 *ttmsg = check_and_cast<HwMsg2 *>(msg);
    ttmsg->getArrivalGate()->getIndex();
    ttmsg->setGate(ttmsg->getSize(),ttmsg->getPreGate());
    ttmsg->setSrc(ttmsg->getSize(), ttmsg->getSource());
    ttmsg->setDes(ttmsg->getSize(), getIndex());
    ttmsg->setDistances(ttmsg->getSize(), sqrt(pow(xpos-ttmsg->getXpos(), 2) + pow(ypos-ttmsg->getYpos(), 2)));
    ttmsg->setSize(ttmsg->getSize() + 1);
    if (count > 0) {

        int n = ttmsg->getSize();
        for(int i = 0; i <= n; i++){
            if(ttmsg->getSrc(i) == getIndex()){
                int check = 0;
                for(int j = 0; j < size; j++)
                    if(ttmsg->getDes(i) == neighbors[j]){
                        check = 1;
                        break;
                    }
                if (check == 0){
                    neighbors[size - count] = ttmsg->getDes(i);
                    distances[size - count] = ttmsg->getDistances(i);
                    gates[size - count] = ttmsg->getGate(i);
                    count--;
                    if (count == 0){
                        double tempDis;
                        int tempNei;
                        int tempGate;
                        for(int i = 0; i< size; i++){
                            for(int j=0; j< size; j++){
                                if(distances[i] > distances[j]){
                                    tempDis = distances[i];
                                    tempNei = neighbors[i];
                                    tempGate = gates[i];

                                    distances[i] = distances[j];
                                    neighbors[i] = neighbors[j];
                                    gates[i] = gates[j];

                                    distances[j] = tempDis;
                                    neighbors[j] = tempNei;
                                    gates[j] = tempGate;
                                }
                            }
                        }
                        ttmsg->setNodeCount(ttmsg->getNodeCount() - 1);
                    }
                }
            }
        }
        ttmsg->setSource(getIndex());
        ttmsg->setXpos(xpos);
        ttmsg->setYpos(ypos);
        forwardMessage(ttmsg);
    }
    else {
        if(ttmsg->getNodeCount() == 0){
            int isSended = 0;
            int gate = 0;
            for(int i = 0; i < size; i++)
                if(checked[i] == 0){
                    isSended = 1;
                    EV << "Send: from "<< getIndex()<< "\n";
                    checked[i] = 1;
                    ttmsg->setTrace(getIndex(),ttmsg->getTraceCount());
                    ttmsg->setTraceCount(ttmsg->getTraceCount() + 1);
                    gate = i;
                    break;
                }
            if(isSended == 0){
                for(int i = 1; i < size; i++){
                    checked[i] = 0;
                }
                send(ttmsg, "out", gate);
            }else
                send(ttmsg, "out", gates[gate]);
            if(getIndex() == finish){
                for(int i = 0; i  < ttmsg->getTraceCount(); i++){
                   EV << ttmsg->getTrace(i) << " ";
                }
                delete ttmsg;
            }
        }else{
            ttmsg->setSource(getIndex());
            ttmsg->setXpos(xpos);
            ttmsg->setYpos(ypos);
            forwardMessage(ttmsg);
        }
    }
}

HwMsg2 *Hw2::generateMessage()
{
    int src = getIndex();
    char msgname[20];
    sprintf(msgname, "node-%d", src);

    HwMsg2 *msg = new HwMsg2(msgname);
    msg->setSource(src);
    msg->setXpos(xpos);
    msg->setYpos(ypos);
    return msg;
}

void Hw2::forwardMessage(HwMsg2 *msg)
{
    int checkedGate = 0;
    int gate = 0;
    for(int i = 0; i < size; i++){
        if (checkedGates[i] == 0){
            checkedGate = 1;
            gate = i;
            break;
        }
    }
    if(checkedGate == 0){
        for(int i = 0; i< size; i++)
            checkedGates[i] = 0;
    }
    msg->setPreGate(gate);
    checkedGates[gate] = 1;
    EV << "Sending message " << ", Node = "<< getIndex()<< ", gate = "<< gate <<", NodeCount = "<<msg->getNodeCount()<<", count ="<<count<<", size = "<<msg->getSize()<<"\n";
    send(msg, "out", gate);
}


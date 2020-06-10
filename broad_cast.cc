#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

class BroadCast : public cSimpleModule{
    private:
        int counter;

    protected:
        virtual void forwardMessage(cMessage *msg);
        virtual void initialize() override;
        virtual void handleMessage(cMessage * msg) override;
};

Define_Module(BroadCast);

void BroadCast::initialize(){
    counter = gateSize("out");
    if(getIndex() == 0){
        cMessage *msg = new cMessage("node[0] broadcast");
       forwardMessage(msg);
    }
}

void BroadCast::handleMessage(cMessage *msg){
    EV <<msg<<"\n";
    forwardMessage(msg);
}

void BroadCast::forwardMessage(cMessage *msg){
    for(int i = 0; i < gateSize("out"); i++){
        send(msg, "out", i);
    }
}

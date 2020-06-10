//
// Generated file, do not edit! Created by nedtool 5.6 from hw2.msg.
//

#ifndef __HW2_M_H
#define __HW2_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0506
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>hw2.msg:16</tt> by nedtool.
 * <pre>
 * //
 * // This program is free software: you can redistribute it and/or modify
 * // it under the terms of the GNU Lesser General Public License as published by
 * // the Free Software Foundation, either version 3 of the License, or
 * // (at your option) any later version.
 * // 
 * // This program is distributed in the hope that it will be useful,
 * // but WITHOUT ANY WARRANTY; without even the implied warranty of
 * // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * // GNU Lesser General Public License for more details.
 * // 
 * // You should have received a copy of the GNU Lesser General Public License
 * // along with this program.  If not, see http://www.gnu.org/licenses/.
 * //
 * message HwMsg2
 * {
 *     int source;
 *     int trace[200];
 *     int traceCount = 0;
 *     int nodeCount = 100;
 * 
 *     double xpos;
 *     double ypos;
 * 
 *     int src[10000];
 *     int des[10000];
 *     double distances[10000];
 *     int gate[10000];
 *     int preGate = -1;
 *     int size = 0;
 * }
 * </pre>
 */
class HwMsg2 : public ::omnetpp::cMessage
{
  protected:
    int source;
    int trace[200];
    int traceCount;
    int nodeCount;
    double xpos;
    double ypos;
    int src[10000];
    int des[10000];
    double distances[10000];
    int gate[10000];
    int preGate;
    int size;

  private:
    void copy(const HwMsg2& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const HwMsg2&);

  public:
    HwMsg2(const char *name=nullptr, short kind=0);
    HwMsg2(const HwMsg2& other);
    virtual ~HwMsg2();
    HwMsg2& operator=(const HwMsg2& other);
    virtual HwMsg2 *dup() const override {return new HwMsg2(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getSource() const;
    virtual void setSource(int source);
    virtual unsigned int getTraceArraySize() const;
    virtual int getTrace(unsigned int k) const;
    virtual void setTrace(unsigned int k, int trace);
    virtual int getTraceCount() const;
    virtual void setTraceCount(int traceCount);
    virtual int getNodeCount() const;
    virtual void setNodeCount(int nodeCount);
    virtual double getXpos() const;
    virtual void setXpos(double xpos);
    virtual double getYpos() const;
    virtual void setYpos(double ypos);
    virtual unsigned int getSrcArraySize() const;
    virtual int getSrc(unsigned int k) const;
    virtual void setSrc(unsigned int k, int src);
    virtual unsigned int getDesArraySize() const;
    virtual int getDes(unsigned int k) const;
    virtual void setDes(unsigned int k, int des);
    virtual unsigned int getDistancesArraySize() const;
    virtual double getDistances(unsigned int k) const;
    virtual void setDistances(unsigned int k, double distances);
    virtual unsigned int getGateArraySize() const;
    virtual int getGate(unsigned int k) const;
    virtual void setGate(unsigned int k, int gate);
    virtual int getPreGate() const;
    virtual void setPreGate(int preGate);
    virtual int getSize() const;
    virtual void setSize(int size);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const HwMsg2& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, HwMsg2& obj) {obj.parsimUnpack(b);}


#endif // ifndef __HW2_M_H


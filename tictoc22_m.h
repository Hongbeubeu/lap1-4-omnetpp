//
// Generated file, do not edit! Created by nedtool 5.6 from tictoc22.msg.
//

#ifndef __TICTOC22_M_H
#define __TICTOC22_M_H

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
 * Class generated from <tt>tictoc22.msg:16</tt> by nedtool.
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
 * message TicTocMsg22
 * {
 *     int source;
 *     int destination;
 *     int hopCount = 0;
 *     int preNode;
 *     int map[169] = 0;
 * }
 * </pre>
 */
class TicTocMsg22 : public ::omnetpp::cMessage
{
  protected:
    int source;
    int destination;
    int hopCount;
    int preNode;
    int map[169];

  private:
    void copy(const TicTocMsg22& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const TicTocMsg22&);

  public:
    TicTocMsg22(const char *name=nullptr, short kind=0);
    TicTocMsg22(const TicTocMsg22& other);
    virtual ~TicTocMsg22();
    TicTocMsg22& operator=(const TicTocMsg22& other);
    virtual TicTocMsg22 *dup() const override {return new TicTocMsg22(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getSource() const;
    virtual void setSource(int source);
    virtual int getDestination() const;
    virtual void setDestination(int destination);
    virtual int getHopCount() const;
    virtual void setHopCount(int hopCount);
    virtual int getPreNode() const;
    virtual void setPreNode(int preNode);
    virtual unsigned int getMapArraySize() const;
    virtual int getMap(unsigned int k) const;
    virtual void setMap(unsigned int k, int map);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const TicTocMsg22& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, TicTocMsg22& obj) {obj.parsimUnpack(b);}


#endif // ifndef __TICTOC22_M_H


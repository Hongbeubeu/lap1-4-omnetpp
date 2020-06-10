//
// Generated file, do not edit! Created by nedtool 5.6 from hw2.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "hw2_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp


// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(HwMsg2)

HwMsg2::HwMsg2(const char *name, short kind) : ::omnetpp::cMessage(name,kind)
{
    this->source = 0;
    for (unsigned int i=0; i<200; i++)
        this->trace[i] = 0;
    this->traceCount = 0;
    this->nodeCount = 100;
    this->xpos = 0;
    this->ypos = 0;
    for (unsigned int i=0; i<10000; i++)
        this->src[i] = 0;
    for (unsigned int i=0; i<10000; i++)
        this->des[i] = 0;
    for (unsigned int i=0; i<10000; i++)
        this->distances[i] = 0;
    for (unsigned int i=0; i<10000; i++)
        this->gate[i] = 0;
    this->preGate = -1;
    this->size = 0;
}

HwMsg2::HwMsg2(const HwMsg2& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

HwMsg2::~HwMsg2()
{
}

HwMsg2& HwMsg2::operator=(const HwMsg2& other)
{
    if (this==&other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void HwMsg2::copy(const HwMsg2& other)
{
    this->source = other.source;
    for (unsigned int i=0; i<200; i++)
        this->trace[i] = other.trace[i];
    this->traceCount = other.traceCount;
    this->nodeCount = other.nodeCount;
    this->xpos = other.xpos;
    this->ypos = other.ypos;
    for (unsigned int i=0; i<10000; i++)
        this->src[i] = other.src[i];
    for (unsigned int i=0; i<10000; i++)
        this->des[i] = other.des[i];
    for (unsigned int i=0; i<10000; i++)
        this->distances[i] = other.distances[i];
    for (unsigned int i=0; i<10000; i++)
        this->gate[i] = other.gate[i];
    this->preGate = other.preGate;
    this->size = other.size;
}

void HwMsg2::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->source);
    doParsimArrayPacking(b,this->trace,200);
    doParsimPacking(b,this->traceCount);
    doParsimPacking(b,this->nodeCount);
    doParsimPacking(b,this->xpos);
    doParsimPacking(b,this->ypos);
    doParsimArrayPacking(b,this->src,10000);
    doParsimArrayPacking(b,this->des,10000);
    doParsimArrayPacking(b,this->distances,10000);
    doParsimArrayPacking(b,this->gate,10000);
    doParsimPacking(b,this->preGate);
    doParsimPacking(b,this->size);
}

void HwMsg2::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->source);
    doParsimArrayUnpacking(b,this->trace,200);
    doParsimUnpacking(b,this->traceCount);
    doParsimUnpacking(b,this->nodeCount);
    doParsimUnpacking(b,this->xpos);
    doParsimUnpacking(b,this->ypos);
    doParsimArrayUnpacking(b,this->src,10000);
    doParsimArrayUnpacking(b,this->des,10000);
    doParsimArrayUnpacking(b,this->distances,10000);
    doParsimArrayUnpacking(b,this->gate,10000);
    doParsimUnpacking(b,this->preGate);
    doParsimUnpacking(b,this->size);
}

int HwMsg2::getSource() const
{
    return this->source;
}

void HwMsg2::setSource(int source)
{
    this->source = source;
}

unsigned int HwMsg2::getTraceArraySize() const
{
    return 200;
}

int HwMsg2::getTrace(unsigned int k) const
{
    if (k>=200) throw omnetpp::cRuntimeError("Array of size 200 indexed by %lu", (unsigned long)k);
    return this->trace[k];
}

void HwMsg2::setTrace(unsigned int k, int trace)
{
    if (k>=200) throw omnetpp::cRuntimeError("Array of size 200 indexed by %lu", (unsigned long)k);
    this->trace[k] = trace;
}

int HwMsg2::getTraceCount() const
{
    return this->traceCount;
}

void HwMsg2::setTraceCount(int traceCount)
{
    this->traceCount = traceCount;
}

int HwMsg2::getNodeCount() const
{
    return this->nodeCount;
}

void HwMsg2::setNodeCount(int nodeCount)
{
    this->nodeCount = nodeCount;
}

double HwMsg2::getXpos() const
{
    return this->xpos;
}

void HwMsg2::setXpos(double xpos)
{
    this->xpos = xpos;
}

double HwMsg2::getYpos() const
{
    return this->ypos;
}

void HwMsg2::setYpos(double ypos)
{
    this->ypos = ypos;
}

unsigned int HwMsg2::getSrcArraySize() const
{
    return 10000;
}

int HwMsg2::getSrc(unsigned int k) const
{
    if (k>=10000) throw omnetpp::cRuntimeError("Array of size 10000 indexed by %lu", (unsigned long)k);
    return this->src[k];
}

void HwMsg2::setSrc(unsigned int k, int src)
{
    if (k>=10000) throw omnetpp::cRuntimeError("Array of size 10000 indexed by %lu", (unsigned long)k);
    this->src[k] = src;
}

unsigned int HwMsg2::getDesArraySize() const
{
    return 10000;
}

int HwMsg2::getDes(unsigned int k) const
{
    if (k>=10000) throw omnetpp::cRuntimeError("Array of size 10000 indexed by %lu", (unsigned long)k);
    return this->des[k];
}

void HwMsg2::setDes(unsigned int k, int des)
{
    if (k>=10000) throw omnetpp::cRuntimeError("Array of size 10000 indexed by %lu", (unsigned long)k);
    this->des[k] = des;
}

unsigned int HwMsg2::getDistancesArraySize() const
{
    return 10000;
}

double HwMsg2::getDistances(unsigned int k) const
{
    if (k>=10000) throw omnetpp::cRuntimeError("Array of size 10000 indexed by %lu", (unsigned long)k);
    return this->distances[k];
}

void HwMsg2::setDistances(unsigned int k, double distances)
{
    if (k>=10000) throw omnetpp::cRuntimeError("Array of size 10000 indexed by %lu", (unsigned long)k);
    this->distances[k] = distances;
}

unsigned int HwMsg2::getGateArraySize() const
{
    return 10000;
}

int HwMsg2::getGate(unsigned int k) const
{
    if (k>=10000) throw omnetpp::cRuntimeError("Array of size 10000 indexed by %lu", (unsigned long)k);
    return this->gate[k];
}

void HwMsg2::setGate(unsigned int k, int gate)
{
    if (k>=10000) throw omnetpp::cRuntimeError("Array of size 10000 indexed by %lu", (unsigned long)k);
    this->gate[k] = gate;
}

int HwMsg2::getPreGate() const
{
    return this->preGate;
}

void HwMsg2::setPreGate(int preGate)
{
    this->preGate = preGate;
}

int HwMsg2::getSize() const
{
    return this->size;
}

void HwMsg2::setSize(int size)
{
    this->size = size;
}

class HwMsg2Descriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    HwMsg2Descriptor();
    virtual ~HwMsg2Descriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(HwMsg2Descriptor)

HwMsg2Descriptor::HwMsg2Descriptor() : omnetpp::cClassDescriptor("HwMsg2", "omnetpp::cMessage")
{
    propertynames = nullptr;
}

HwMsg2Descriptor::~HwMsg2Descriptor()
{
    delete[] propertynames;
}

bool HwMsg2Descriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<HwMsg2 *>(obj)!=nullptr;
}

const char **HwMsg2Descriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *HwMsg2Descriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int HwMsg2Descriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 12+basedesc->getFieldCount() : 12;
}

unsigned int HwMsg2Descriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<12) ? fieldTypeFlags[field] : 0;
}

const char *HwMsg2Descriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "source",
        "trace",
        "traceCount",
        "nodeCount",
        "xpos",
        "ypos",
        "src",
        "des",
        "distances",
        "gate",
        "preGate",
        "size",
    };
    return (field>=0 && field<12) ? fieldNames[field] : nullptr;
}

int HwMsg2Descriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "trace")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "traceCount")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "nodeCount")==0) return base+3;
    if (fieldName[0]=='x' && strcmp(fieldName, "xpos")==0) return base+4;
    if (fieldName[0]=='y' && strcmp(fieldName, "ypos")==0) return base+5;
    if (fieldName[0]=='s' && strcmp(fieldName, "src")==0) return base+6;
    if (fieldName[0]=='d' && strcmp(fieldName, "des")==0) return base+7;
    if (fieldName[0]=='d' && strcmp(fieldName, "distances")==0) return base+8;
    if (fieldName[0]=='g' && strcmp(fieldName, "gate")==0) return base+9;
    if (fieldName[0]=='p' && strcmp(fieldName, "preGate")==0) return base+10;
    if (fieldName[0]=='s' && strcmp(fieldName, "size")==0) return base+11;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *HwMsg2Descriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "double",
        "double",
        "int",
        "int",
        "double",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<12) ? fieldTypeStrings[field] : nullptr;
}

const char **HwMsg2Descriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *HwMsg2Descriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int HwMsg2Descriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    HwMsg2 *pp = (HwMsg2 *)object; (void)pp;
    switch (field) {
        case 1: return 200;
        case 6: return 10000;
        case 7: return 10000;
        case 8: return 10000;
        case 9: return 10000;
        default: return 0;
    }
}

const char *HwMsg2Descriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HwMsg2 *pp = (HwMsg2 *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string HwMsg2Descriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HwMsg2 *pp = (HwMsg2 *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSource());
        case 1: return long2string(pp->getTrace(i));
        case 2: return long2string(pp->getTraceCount());
        case 3: return long2string(pp->getNodeCount());
        case 4: return double2string(pp->getXpos());
        case 5: return double2string(pp->getYpos());
        case 6: return long2string(pp->getSrc(i));
        case 7: return long2string(pp->getDes(i));
        case 8: return double2string(pp->getDistances(i));
        case 9: return long2string(pp->getGate(i));
        case 10: return long2string(pp->getPreGate());
        case 11: return long2string(pp->getSize());
        default: return "";
    }
}

bool HwMsg2Descriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    HwMsg2 *pp = (HwMsg2 *)object; (void)pp;
    switch (field) {
        case 0: pp->setSource(string2long(value)); return true;
        case 1: pp->setTrace(i,string2long(value)); return true;
        case 2: pp->setTraceCount(string2long(value)); return true;
        case 3: pp->setNodeCount(string2long(value)); return true;
        case 4: pp->setXpos(string2double(value)); return true;
        case 5: pp->setYpos(string2double(value)); return true;
        case 6: pp->setSrc(i,string2long(value)); return true;
        case 7: pp->setDes(i,string2long(value)); return true;
        case 8: pp->setDistances(i,string2double(value)); return true;
        case 9: pp->setGate(i,string2long(value)); return true;
        case 10: pp->setPreGate(string2long(value)); return true;
        case 11: pp->setSize(string2long(value)); return true;
        default: return false;
    }
}

const char *HwMsg2Descriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *HwMsg2Descriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    HwMsg2 *pp = (HwMsg2 *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}



#ifndef Queue_class
#define Queue_class

#include "Node.h"

class Queue
{
public:
    Queue();
    ~Queue();

    bool        empty() const;
    int         size() const;
    ZIPSA_MSG   front() const;
    void        pushBack(const ZIPSA_MSG data);
    ZIPSA_MSG   popFront();

    void        display() const;

private:
    Node*       m_headNode;
    Node*       m_tailNode;
    int         m_dataSize;
};

#endif
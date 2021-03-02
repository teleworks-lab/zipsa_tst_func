#ifndef Node_class
#define Node_class

#include "msg_data.h"

class Node 
{
public:
    Node(const ZIPSA_MSG data, Node* prev = nullptr, Node* next = nullptr);

    ZIPSA_MSG getData() const;
    Node* getPrev() const;
    Node* getNext() const;
    void setData(const ZIPSA_MSG data);
    void setPrev(Node* node);
    void setNext(Node* node);

private:
    ZIPSA_MSG   m_data;
    Node*       m_prev;
    Node*       m_next;
};

#endif
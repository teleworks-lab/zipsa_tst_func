#include "Node.h"

Node::Node(const ZIPSA_MSG data, Node* prev, Node* next) 
{
    this->m_data = data;
    this->m_prev = prev;
    this->m_next = next;
}

ZIPSA_MSG Node::getData() const
{
    return m_data;
}

Node* Node::getPrev() const 
{
    return m_prev;
}

Node* Node::getNext() const 
{
    return m_next;
}

void Node::setData(const ZIPSA_MSG data) 
{
    this->m_data = data;
}

void Node::setPrev(Node* node) 
{
    this->m_prev = node;
}

void Node::setNext(Node* node) 
{
    this->m_next = node;
}

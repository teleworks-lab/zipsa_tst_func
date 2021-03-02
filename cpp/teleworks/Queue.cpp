#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

inline void error(const char* message)
{
    puts(message);
    exit(EXIT_FAILURE);
}

Queue::Queue()
{
    m_headNode = nullptr;
    m_tailNode = nullptr;
    m_dataSize = 0;
}

Queue::~Queue()
{
    while (!empty())
    {
        popFront();
    }
}

bool Queue::empty() const
{
    return m_dataSize == 0;   // or headNode == nullptr && tailNode == nullptr;
}

int Queue::size() const
{
    return m_dataSize;
}

ZIPSA_MSG Queue::front() const
{
    if (empty())
    {
        error("Queue is empty!");
    }
    return m_headNode->getData();
}

void Queue::pushBack(const ZIPSA_MSG data)
{
    if (empty())
    {
        m_headNode = m_tailNode = new Node(data);
        m_dataSize++;
        return;
    }
    Node* node = new Node(data, m_tailNode, nullptr);
    m_tailNode->setNext(node);
    m_tailNode = node;
    m_dataSize++;
}

ZIPSA_MSG Queue::popFront()
{
    ZIPSA_MSG frontData = front();// if empty, error occurred
    Node* node = m_headNode;
    m_headNode = m_headNode->getNext();
    if (m_headNode != nullptr)
    {
        m_headNode->setPrev(nullptr);
    }
    delete node;
    m_dataSize--;
    return frontData;
}

void Queue::display() const
{
    puts("---------------------------------------------------");
    if (empty()) {
        puts("Queue is empty!");
        puts("---------------------------------------------------");
        return;
    }
    printf("%-5s : %d\n", "size", size());
#if defined(DATA_FORMAT_STRUCTURE)
    printf("%-5s : %ld, %d, %s\n", "front", front().msg_type, front().data.img_format, front().data.file_path);
#else
    printf("%-5s : %s\n", "front", front().c_str());
#endif
    printf("(FRONT) ");
    for (auto i = m_headNode; i != nullptr; i = i->getNext())
    {
#if defined(DATA_FORMAT_STRUCTURE)
        printf("[%ld]: %d, %s \n", i->getData().msg_type, i->getData().data.img_format, i->getData().data.file_path);
#else
        printf(" >> %s\n", i->getData().c_str());
#endif
    }
    puts("(BACK)");
    puts("---------------------------------------------------");
}

#include "queue.h"
#include <cassert>

void enqueue(Queue* queue, int value) // last in first out
{
    Node* currentNode = queue->lastNode;
    Node* node = new Node;
    node->value = value;
    node->next=nullptr;
    if (queue->firstNode==nullptr)
    {
        queue->firstNode = node;
        queue->lastNode = node;
    }
    else
    {
        queue->lastNode->next = node;
        queue->lastNode = node;
    }
    
}

int dequeue(Queue* queue)
{
    assert(queue->firstNode!=nullptr);

    Node* temp = queue->firstNode;
    queue->firstNode = queue->firstNode->next;

    if (queue->firstNode->next==nullptr)
    {
        queue->lastNode=nullptr;
    }

    

    delete temp;
    return 1;
}

bool isEmpty(Queue* queue)
{
    if (queue->firstNode==nullptr)
    {
        return true;
    }
    return false;
}
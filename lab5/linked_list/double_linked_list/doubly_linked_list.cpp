#include "doubly_linked_list.h"
#include <cassert>

Node* insertAfter(DoublyLinkedList* list, Node* node, int value)
{
    Node* nodeNew = new Node;
    nodeNew->nextNode=nullptr;
    nodeNew->prevNode=node;
    nodeNew->data=value;

    if (node==nullptr)
    {
        if (list->firstNode != nullptr)
        {
            nodeNew->nextNode=list->firstNode;
            list->firstNode = nodeNew;
        }
        else if (list->firstNode == nullptr)
        {
            list->firstNode = nodeNew;
        }

    }
    
    

    if (node->nextNode==nullptr)
    {
        node->nextNode = nodeNew;
        list->lastNode = nodeNew;
    }
    else // node insertion between two nodes
    {
        nodeNew->nextNode = node->nextNode;
        node->nextNode = nodeNew;
    }
    
    return nodeNew;
}

Node* insertBefore(DoublyLinkedList* list, Node* node, int value) // три случая бефор в начало, бефор в середине, нод нуллптр
{
    Node* nodeNew = new Node;
    nodeNew->nextNode=node;
    nodeNew->data=value;

    if (node==nullptr)
    {
        if (list->lastNode != nullptr)
        {
            nodeNew->prevNode=list->lastNode;
            list->lastNode = nodeNew;
        }
        else if (list->lastNode == nullptr)
        {
            list->lastNode = nodeNew;
        }

    }

    if (node->prevNode==nullptr)
    {
        node->prevNode = nodeNew;
        list->firstNode=nodeNew;
    }
    else
    {
        nodeNew->prevNode = node->prevNode;
        node->prevNode->nextNode=nodeNew;
        node->prevNode = nodeNew;
    }
    
    
    return nodeNew;

}

Node* find(DoublyLinkedList* list, int value)
{
    Node* node = list->firstNode;
    while (node!=nullptr)
    {
        if (node->data==value)
        {
            return node;
        }
        node = node->nextNode;
    }
    return nullptr;
}

void remove(Node* node, DoublyLinkedList* list)
{
    if (node == list->firstNode)
    {
        list->firstNode = node->nextNode;
        node->nextNode->prevNode = nullptr;
    }
    else if (node == list->lastNode)
    {
        list->lastNode = node->prevNode;
        node->prevNode->nextNode = nullptr;
    }
    else
    {
        node->prevNode->nextNode = node->nextNode;
        node->nextNode->prevNode = node->prevNode;
    }
    
    delete node;
}
void assertNoCycles(DoublyLinkedList* list)
{

    if(list->firstNode == nullptr || list->firstNode->nextNode==nullptr)
        return;    

    assert(list->lastNode->nextNode == nullptr);
    
    Node* nodeOneStep = list->firstNode;
    Node* nodeTwoStep = list->firstNode;

    while (nodeTwoStep && nodeTwoStep->nextNode) 
    {
        nodeOneStep = nodeOneStep->nextNode;      
        nodeTwoStep = nodeTwoStep->nextNode->nextNode;       

        assert(nodeOneStep!=nodeTwoStep);
    }

    nodeOneStep = list->firstNode;
    nodeTwoStep = list->firstNode;

    while (nodeTwoStep && nodeTwoStep->prevNode) 
    {
        nodeOneStep = nodeOneStep->prevNode;      
        nodeTwoStep = nodeTwoStep->prevNode->prevNode;       

        assert(nodeOneStep!=nodeTwoStep);
    }

}

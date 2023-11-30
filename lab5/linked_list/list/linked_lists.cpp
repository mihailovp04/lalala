#include "linked_lists.h"
#include <cassert>

Node* insertAfter(LinkedList* list, Node* node, int value)
{
    Node* nodeNew = new Node;
    nodeNew->nextNode=nullptr;
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
    else if (node->nextNode==nullptr)
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

FindNodeResult find(LinkedList* list, int value)
{
    Node* currentNode = list->firstNode;
    FindNodeResult result{0,0};
    if (currentNode==nullptr)
        return result;

    result.previousNode = currentNode;

    while (currentNode->nextNode!=nullptr)
    {
        if (currentNode->data!=value)
        {
            result.previousNode = currentNode;
            currentNode = currentNode->nextNode;
            continue;
        }
        
        result.foundValueNode = currentNode;
        return result;   
    }
    result.foundValueNode=0;
    result.previousNode=0;
    return result;
}

void removeAfter(LinkedList* list, Node* node)
{
    Node* nodeToRemove;
    if (node->nextNode==nullptr)
        return;
    if (node == nullptr)
    {
        delete list->firstNode;
    }

    nodeToRemove=node->nextNode;
    node->nextNode = node->nextNode->nextNode;
    delete nodeToRemove;    
}

void assertNoCycles(LinkedList* list)
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
    
    
}
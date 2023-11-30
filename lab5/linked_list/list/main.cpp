#include "linked_lists.h"
#include <iostream>

using std::cout, std::endl;

int main()
{
    LinkedList* list = new LinkedList;
    insertAfter(list,list->firstNode,0);
    cout<<"first node val: "<<list->firstNode->data<<" last node val: "<<list->lastNode->data<<endl;
    Node* node = list->firstNode;
    for (int i = 1; i < 6; i++)
    {
        insertAfter(list,node,i);
        node = node->nextNode;
    }

    FindNodeResult result = find(list,4);
    cout<<"prev node val: "<<result.previousNode->data<<" found node val: "<<result.foundValueNode->data<<endl;
    
    removeAfter(list,result.previousNode);
    cout<<"next node val "<<result.previousNode->nextNode->data<<endl;

    assertNoCycles(list);
    cout<<"assert work1"<<endl;

    list->firstNode->nextNode = list->firstNode;

    assertNoCycles(list);
    cout<<"assert dont work2"<<endl;
}
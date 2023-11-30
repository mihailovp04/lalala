#include "doubly_linked_list.h"
#include <iostream>

using std::cout, std::endl;

int main()
{
    DoublyLinkedList* list = new DoublyLinkedList;
    insertAfter(list,list->firstNode,0);
    insertBefore(list,list->firstNode,-1);

    cout<<"first val: "<<list->firstNode->data<<endl;
    Node* node1 = list->lastNode;
    for (int i = 0; i < 5; i++)
    {
        insertAfter(list,node1,i+1);
        node1 = node1->nextNode;
    }
    cout<<"last val: "<<list->lastNode->data<<endl;

    Node* node2 = find(list,3);

    remove(node2);

    node2 = list->firstNode;
    while (node2 != nullptr)
    {
        cout<<"node forward listing: "<<node2->data<<endl;
        node2=node2->nextNode;
    }
    cout<<endl;
    node2 = list->lastNode;
    while (node2 != nullptr)
    {
        cout<<"node backward listing: "<<node2->data<<endl;
        node2=node2->prevNode;
    }
        

    assertNoCycles(list);
    cout<<"no cycles detected1"<<endl;

    //list->lastNode->prevNode->nextNode = list->firstNode->nextNode; // create forward cycle

    list->firstNode->prevNode=list->lastNode->prevNode; // create backward cycle

    assertNoCycles(list);
    cout<<"no cycles detected"<<endl;
    
}
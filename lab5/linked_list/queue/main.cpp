#include "queue.h"
#include <iostream>
using std::cout, std::endl;
int main()
{
    Queue* queue = new Queue;
    enqueue(queue,1);
    enqueue(queue,2);
    enqueue(queue,3);
    enqueue(queue,4);
    enqueue(queue,5);

    dequeue(queue);
    cout<<"queue first node val: "<<queue->firstNode->value<<endl;

    dequeue(queue);
    dequeue(queue);

    cout<<"isempty:  "<<isEmpty(queue)<<endl;
    cout<<"queue first node val: "<<queue->firstNode->value<<endl;

    dequeue(queue);
    dequeue(queue);

    cout<<"isempty:  "<<isEmpty(queue)<<endl;

    enqueue(queue,69);
    cout<<"queue first node val: "<<queue->firstNode->value<<endl;
    cout<<"isempty:  "<<isEmpty(queue)<<endl;


}
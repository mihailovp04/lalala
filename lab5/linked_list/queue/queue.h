struct Node
{
    int value;
    Node* next = nullptr;
};

struct Queue
{
    Node* firstNode = nullptr;
    Node* lastNode = nullptr;
};

void enqueue(Queue* queue, int value); // last in first out

int dequeue(Queue* queue);

bool isEmpty(Queue* queue);
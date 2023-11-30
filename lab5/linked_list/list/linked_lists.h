struct Node
{
    int data;
    Node* nextNode=nullptr;
};
struct LinkedList
{
    Node* firstNode=nullptr;
    Node* lastNode=nullptr;
};
struct FindNodeResult
{
    Node* previousNode = nullptr;
    Node* foundValueNode = nullptr;
};


Node* insertAfter(LinkedList* list, Node* node, int value);
FindNodeResult find(LinkedList* list, int value);
void removeAfter(LinkedList* list, Node* node);
void assertNoCycles(LinkedList* list);
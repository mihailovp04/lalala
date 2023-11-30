struct Node
{
    int data;
    Node* nextNode = nullptr;
    Node* prevNode = nullptr;
};
struct DoublyLinkedList
{
    Node* firstNode = nullptr;
    Node* lastNode = nullptr;
};

void assertNoCycles(DoublyLinkedList* list);
void remove(Node* node,DoublyLinkedList* list);
Node* find(DoublyLinkedList* list, int value);
Node* insertBefore(DoublyLinkedList* list, Node* node, int value);
Node* insertAfter(DoublyLinkedList* list, Node* node, int value);
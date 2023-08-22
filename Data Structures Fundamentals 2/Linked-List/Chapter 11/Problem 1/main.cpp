#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node* next;
    Node* previous;
    ~Node()
    {
        std::cout << "Deleting Node -> " << data << std::endl;
    }
};

template <typename P>
class LinkedList
{
private:
    Node<P>* head;
public:
    LinkedList() : head(nullptr) {}
    void Push(P value)
    {
        Node<P>* node = new Node<P>();
        node->data = value;
        node->next = head;
        node->previous = nullptr;
        if (head != nullptr)
        {
            head->previous = node;
        }        
        head = node;
    }

    void Remove()
    {
        if (head == nullptr)
        {
            std::cout << "Linked list is empty." << std::endl;
            return;
        }
        head = head->next;
        delete head->previous;
        head->previous = nullptr;
    }

    void Print()
    {
        Node<P>* node = new Node<P>();
        node = head;
        while (node != nullptr)
        {
            std::cout << "Node -> " << node->data << std::endl;
            node = node->next;
        }
    }
};

int main()
{
    LinkedList<int>* ll = new LinkedList<int>();
    ll->Remove();
    ll->Push(10);
    ll->Push(20);
    ll->Push(30);
    ll->Push(40);
    ll->Print();
    ll->Remove();
    ll->Print();
    ll->Remove();
    ll->Print();
    return 0;
}
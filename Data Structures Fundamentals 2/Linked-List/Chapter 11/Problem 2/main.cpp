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
    void Append(P value)
    {
        Node<P>* node = new Node<P>();
        node->data = value;
        node->next = nullptr;
        node->previous = nullptr;
        if (head == nullptr)
        {
            head = node;
            return;
        }
        Node<P>* prev = head;
        while (prev->next != nullptr)
        {
            prev = prev->next;
        }
        prev->next = node;
        node->previous = prev;
    }

    void Pop()
    {
        if (head == nullptr)
        {
            std::cout << "Linked list is empty." << std::endl;
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node<P>* node = head;
        while (node->next != nullptr)
        {
            node = node->next;
        }
        node->previous->next = nullptr;
        delete node;
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
    ll->Append(10);
    ll->Append(20);
    ll->Append(30);
    ll->Append(40);
    ll->Print();
    ll->Pop();
    ll->Print();
    return 0;
}
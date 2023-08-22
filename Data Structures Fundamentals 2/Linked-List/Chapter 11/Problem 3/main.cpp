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

    void Reverse()
    {
        if (head == nullptr)
        {
            std::cout << "Linked list is empty." << std::endl;
            return;
        }
        if (head->next == nullptr)
        {
            return;
        }
        Node<P>* current = head;
        Node<P>* prev = nullptr;
        while (current != nullptr)
        {
            prev = current->previous;
            current->previous = current->next;
            current->next = prev;
            current = current->previous;
        }
        if (prev != nullptr)
        {
            head = prev->previous;
        }
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
    ll->Push(10);
    ll->Push(20);
    ll->Push(30);
    ll->Push(40);
    ll->Print();
    std::cout << "Reversing the Linked-List:" << std::endl;
    ll->Reverse();
    ll->Print();
    return 0;
}
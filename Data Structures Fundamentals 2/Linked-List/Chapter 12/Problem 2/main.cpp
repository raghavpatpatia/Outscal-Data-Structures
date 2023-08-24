#include <iostream>

template <typename T>
class Node
{
public:
    Node() : next(nullptr){}
    T data;
    Node* next;    
    ~Node()
    {
        std::cout << "Deleting Node -> " << data << std::endl;
    }
};

template <typename P>
class CircularLinkedList
{
private:
    Node<P>* head;
public:
    CircularLinkedList() : head(nullptr){}
    void Append(P value)
    {
        Node<P>* node = new Node<P>();
        node->data = value;
        if (head == nullptr)
        {
            node->next = node;
            head = node;
            return;
        }
        Node<P>* last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        node->next = last->next;
        last->next = node;
    }

    void Pop()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node<P>* node = head;
        Node<P>* prev = nullptr;
        while (node->next != head)
        {
            prev = node;
            node = node->next;
        }
        prev->next = head;
        delete node;
    }

    void Print()
    {
        if (head == nullptr)
        {
            std::cout << "Linked List is empty." << std::endl;
            return;
        }
        Node<P>* node = head;
        std::cout << "Printing linked-List: " << std::endl;
        do
        {
            std::cout << "Node -> " << node->data << std::endl;
            node = node->next;
        }while (node != head);
    }
};

int main()
{
    CircularLinkedList<int>* ll = new CircularLinkedList<int>();
    ll->Print();
    ll->Pop();
    ll->Print();
    ll->Append(10);
    ll->Pop();
    ll->Print();
    ll->Append(20);
    ll->Append(30);
    ll->Append(40);
    ll->Append(50);
    ll->Append(60);
    ll->Append(70);
    ll->Print();
    ll->Pop();
    ll->Print();
    ll->Pop();
    ll->Print();
    return 0;
}
#include <iostream>

template <typename T>
class Node
{
public:
    Node() : next(nullptr) {}
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
    void Push(P value)
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
        node->next = head;
        last->next = node;
        head = node;
    }
    void Remove()
    {
        if (head == nullptr)
        {
            std::cout << "Linded-List is empty." << std::endl;
        }

        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node<P>* tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }

        Node<P>* node = head;
        head = head->next;
        tail->next = head;
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
        std::cout << "Printing Linked List: " << std::endl;
        do
        {
            std::cout << "Node -> " << node->data << std::endl;
            node = node->next;
        }while(node != head);
    }
};

int main()
{
    CircularLinkedList<int>* ll = new CircularLinkedList<int>();
    ll->Push(10);
    ll->Push(20);
    ll->Push(30);
    ll->Push(40);
    ll->Push(50);
    ll->Print();
    ll->Remove();
    ll->Print();
    ll->Remove();
    ll->Print();
    return 0;
}
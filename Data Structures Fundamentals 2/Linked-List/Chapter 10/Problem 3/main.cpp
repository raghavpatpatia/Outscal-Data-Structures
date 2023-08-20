#include <iostream>

template<typename T>
class Node
{
public:
    T data;
    Node* next;
};

template<typename P>
class LinkedList
{
private:
    Node<P>* head;
    Node<P>* tail;
public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void InsertAtHead(P value)
    {
        Node<P>* node = new Node<P>();
        node->data = value;
        if (head != NULL)
        {
            node->next = head;
            head = node;
        }
        else
        {
            head = node;
            tail = node;
        }
    }

    void InsertAtTail(P value)
    {
        Node<P>* node = new Node<P>();
        node->data = value;
        if (tail != NULL)
        {
            tail->next = node;
            tail = node;
        }
        else
        {
            tail = node;
            head = node;
        }
    }

    void Print()
    {
        Node<P>* node = head;
        while (node != NULL)
        {
            std:: cout << "Node -> " << node->data << std::endl;
            node = node->next;
        }
    }
};

int main()
{
    LinkedList<int>* ll = new LinkedList<int>();
    ll->InsertAtHead(10);
    ll->InsertAtHead(20);
    ll->InsertAtTail(30);
    ll->InsertAtTail(40);
    ll->Print();
    return 0;
}
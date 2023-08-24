#include <iostream>

template <typename T>
class Node
{
public:
    Node() : next(nullptr){}
    T data;
    Node* next;
};

template <typename P>
class CircularLinkedList
{
private:
    Node<P>* head;
    int count;
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

    int Count()
    {
        if (head == nullptr) {return 0;}
        count = 1;
        Node<P>* node = head;
        while(node->next != head)
        {
            count++;
            node = node->next;
        }
        return count;
    }
};

int main()
{
    CircularLinkedList<int>* ll = new CircularLinkedList<int>();
    std::cout << "Total numbers of nodes in circular linked list are: " << ll->Count() << std::endl;
    ll->Print();
    ll->Append(10);
    std::cout << "Total numbers of nodes in circular linked list are: " << ll->Count() << std::endl;
    ll->Print();
    ll->Append(20);
    ll->Append(30);
    ll->Append(40);
    std::cout << "Total numbers of nodes in circular linked list are: " << ll->Count() << std::endl;
    ll->Print();
    ll->Append(50);
    std::cout << "Total numbers of nodes in circular linked list are: " << ll->Count() << std::endl;
    ll->Print();
    ll->Append(60);
    ll->Append(70);
    ll->Append(80);
    std::cout << "Total numbers of nodes in circular linked list are: " << ll->Count() << std::endl;
    ll->Print();
    return 0;
}
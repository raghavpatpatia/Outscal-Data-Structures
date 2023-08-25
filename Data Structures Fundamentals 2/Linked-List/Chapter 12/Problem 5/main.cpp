#include <iostream>

template <typename T>
class Node
{
public: 
    T data;
    Node* next;
};

template <typename P>
class LinkedList
{
private:
    Node<P>* head;
    bool isCircular;

    bool IsCircularLinkedList()
    {
        Node<P>* node = head;
        isCircular = false;
        while (node != nullptr)
        {
            if (node->next == head)
            {
                isCircular = true;
                break;
            }
            node = node->next;
        }
        return isCircular; 
    }

public: 
    LinkedList() : head(nullptr){}

    void Push(int value)
    {
        Node<P>* node = new Node<P>();
        node->data = value;
        node->next = nullptr;
        if (head != nullptr)
        {
            node->next = head;
            head = node;
        }
        else
        {
            head = node;
        }
    }

    void Print()
    {
        if (head == nullptr)
        {
            std::cout << "Linked List is empty." << std::endl;
            return;
        }
        Node<P>* node = head;
        if (IsCircularLinkedList())
        {
            std::cout << "It is a circular Linked-List" << std::endl;
            do
            {
                std::cout << "Node -> " << node->data << std::endl;
                node = node->next;
            } while (node != head);
        }
        else if (!IsCircularLinkedList())
        {
            std::cout << "It is a singly Linked-List" << std::endl;
            while (node != nullptr)
            {
                std::cout << "Node -> " << node->data << std::endl;
                node = node->next;
            }
        }
    }

    void SinglytoCircularLinkedList()
    {
        if (head == nullptr) { return; }
        Node<P>* node = head;
        while (node->next != nullptr)
        {
            node = node->next;
        }
        node->next = head;
    }
};

int main()
{
    LinkedList<int>* ll = new LinkedList<int>();
    ll->Push(50);
    ll->Push(40);
    ll->Push(30);
    ll->Push(20);
    ll->Push(10);
    ll->Print();
    ll->SinglytoCircularLinkedList();
    ll->Print();
    return 0;
}
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
class LinkedList
{
private:
    Node<P>* head;
    bool isCircular;
public: 
    LinkedList() : head(nullptr){}
    void Append(int value)
    {
        Node<P>* node = new Node<P>();
        node->data = value;
        if (head == nullptr)
        {
            node->next = node;
            head = node;      
            return;      
        }
        Node<P>* lastNode = head;
        while (lastNode->next != head)
        {
            lastNode = lastNode->next;
        } 
        node->next = head;
        lastNode->next = node;
    }

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
        while (node != nullptr)
        {
            std::cout << "Node -> " << node->data << std::endl;
            if (node->next == head)
            {
                break;
            }
            node = node->next;
        }   
    }

    bool isCircularLinkedList()
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
};

int main()
{
    LinkedList<int>* ll = new LinkedList<int>();
    LinkedList<int>* ll2 = new LinkedList<int>();
    ll->Append(10);
    ll->Append(20);
    ll->Append(30);
    ll->Append(40);
    ll->Append(50);
    std::cout << "Is Linked-List 1 a Circular Linked-List: " << (ll->isCircularLinkedList()? "Yes" : "No") << std::endl;
    ll->Print();
    ll2->Push(1);
    ll2->Push(2);
    ll2->Push(3);
    ll2->Push(4);
    ll2->Push(5);
    std::cout << "Is Linked-List 2 a Circular Linked-List: " << (ll2->isCircularLinkedList() ? "Yes" : "No") << std::endl;
    ll2->Print();
    return 0;
}
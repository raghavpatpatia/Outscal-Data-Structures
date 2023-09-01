#include <iostream>

template <typename T>
class Node
{
public:
    Node() : next(nullptr) {}
    T data;
    Node* next;
};

template <typename P>
class LinkedList
{
private:
    Node<P>* head;
public: 
    LinkedList() : head(nullptr){}
    void Append(P value)
    {
        Node<P>* node = new Node<P>();
        node->data = value;
        if (head == nullptr)
        {
            head = node;
            return; 
        }
        Node<P>* lastNode = head;
        while (lastNode->next != nullptr)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = node;
    }

    void GetMiddle()
    {
        if (head == nullptr || head->next == nullptr)
        { 
            std::cout << "Not enough elements. "<< std::endl;
            return; 
        }
        Node<P>* first = head;
        Node<P>* second = head;
        while (second != nullptr && second->next != nullptr)
        {
            first = first->next;
            second = second->next->next;
        }
        std::cout << "Middle Node is: " << first->data << std::endl;
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
            node = node->next;
        }
    }
};

int main()
{
    LinkedList<int> * ll = new LinkedList<int>();
    ll->Append(10);
    ll->Append(20);
    ll->Append(30);
    ll->Append(40);
    ll->Append(50);
    ll->Append(60);
    ll->Print();
    ll->GetMiddle();
    return 0;
}
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
    LinkedList() : head(nullptr) {}
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

    Node<P>* Rotate(int k)
    {
        if (head == nullptr || head->next == nullptr || k == 0) return head;
        
        int length = 1;
        Node<P>* node = head;
        while (node->next != nullptr)
        {
            ++length;
            node = node->next;
        }
        node->next = head;

        k = k % length;
        int end = length - k;
        while (end--)
        {
            node = node->next;
        }
        head = node->next;
        node->next = nullptr;

        return head;
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
    LinkedList<int>* ll = new LinkedList<int>();
    ll->Append(1);
    ll->Append(2);
    ll->Append(3);
    ll->Append(4);
    ll->Append(5);
    std::cout << "Printing Linked List:" << std::endl;
    ll->Print();
    std::cout << "Rotating Linked List" << std::endl; 
    ll->Rotate(2);
    std::cout << "Printing Linked List:" << std::endl;
    ll->Print();
    return 0;
}
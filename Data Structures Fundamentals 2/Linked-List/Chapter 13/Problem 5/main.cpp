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

    int GetLength()
    {
        int length = 0;
        Node<P>* node = head;
        while (node != nullptr)
        {
            length++;
            node = node->next;
        }
        return length;
    }

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

    void SwapNodes(int k)
    {
        int n = GetLength();
        
        if ((n < k) || (2 * k - 1 == n))
            return;
        
        Node<P>* first = head;
        Node<P>* prevFirst = nullptr;
        for (int i = 1; i < k; i++)
        {
            prevFirst = first;
            first = first->next;
        }

        Node<P>* second = head;
        Node<P>* prevSecond = nullptr;
        for (int i = 1; i < n - k + 1; i++)
        {
            prevSecond = second;
            second = second->next;
        }

        if (first)
            prevFirst->next = second;

        if (second)
            prevSecond->next = first;

        Node<P>* temp = first->next;
        first->next = second->next;
        second->next = temp;
        
        if (k == 1)
        {
            head = second;
        }
        if (k == n)
        {
            head = first;
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
    std::cout << "Printing Linked List:" << std::endl;
    ll->Print();
    std::cout << "Swapping nodes in Linked List:" << std::endl;
    ll->SwapNodes(2);
    ll->Print();
    return 0;
}
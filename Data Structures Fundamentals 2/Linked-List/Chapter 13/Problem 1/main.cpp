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

    void CreatingLoop(int position)
    {
        if (head == nullptr)
        {
            std::cout << "Can't create a loop." << std::endl;
            return;
        }
        Node<P>* last = head;
        while (last->next != nullptr)
        {
            last = last->next;
        }
        Node<P>* node = head;
        for (int i = 0; i < position; i++)
        {
            node = node->next;
        }
        last->next = node;
    }

    void DetectLoop()
    {
        if (head == nullptr)
        {
            std::cout << "No" << std::endl;
            return;
        }
        Node<P>* first = head;
        Node<P>* second = head;
        while (first != nullptr && second != nullptr && second->next != nullptr)
        {
            first = first->next;
            second = second->next->next;
            if (first == second)
            {
                std::cout << "Yes" << std::endl;
                return;
            }
        }
        std::cout << "No" << std::endl;
    }
};

int main()
{
    LinkedList<int>* ll = new LinkedList<int>();
    ll->DetectLoop();
    ll->Append(10);
    ll->Append(20);
    ll->Append(30);
    ll->Append(40);
    ll->DetectLoop();
    ll->CreatingLoop(1);
    ll->DetectLoop();
    return 0;
}

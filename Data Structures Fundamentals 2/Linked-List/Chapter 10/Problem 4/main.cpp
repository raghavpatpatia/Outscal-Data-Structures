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
public:
    LinkedList()
    {
        head = NULL;
    }
    
    void Push(P value)
    {
        Node<P>* node = new Node<P>();
        node->data = value;
        node->next = NULL;
        if (head != NULL)
        {
            node->next = head;
            head = node;
        }
        else
        {
            head = node;
        }
    }

    void Reverse()
    {
        Node<P>* current = head;
        Node<P>* previous = NULL;
        Node<P>* next = NULL;
        while(current != NULL)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }

    void Print()
    {
        std::cout << "\nPrinting Linked-List: \n";
        Node<P>* node = head;
        while(node!= NULL)
        {
            std::cout << "Node -> " << node->data << std::endl;
            node = node->next;
        }
    }
};

int main()
{
    LinkedList<int>* ll = new LinkedList<int>();
    ll->Push(10);
    ll->Push(20);
    ll->Push(30);
    ll->Push(40);
    ll->Push(50);
    ll->Print();
    ll->Reverse();
    ll->Print();
    return 0;
}
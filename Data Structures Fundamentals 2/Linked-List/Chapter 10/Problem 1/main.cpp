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
    void Append(P value)
    {
        Node<P>* node = new Node<P>();
        node->data = value;
        node->next = NULL;
        if (head == NULL)
        {
            head = node;
        }
        else
        {
            Node<P>* lastNode = head;
            while(lastNode->next != NULL)
            {
                lastNode = lastNode->next;
            }
            lastNode->next = node;
        }
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
    ll->Print();
    ll->Push(20);
    ll->Push(30);
    ll->Push(40);
    ll->Push(50);
    ll->Print();
    ll->Append(9);
    ll->Append(8);
    ll->Append(7);
    ll->Append(6);
    ll->Append(5);
    ll->Append(4);
    ll->Append(3);
    ll->Append(2);
    ll->Append(1);
    ll->Append(0);
    ll->Print();
    return 0;
}
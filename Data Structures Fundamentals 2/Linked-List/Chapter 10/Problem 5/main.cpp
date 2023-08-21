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
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        ll->Push(arr[i]);
    }
    ll->Print();
    return 0;
}
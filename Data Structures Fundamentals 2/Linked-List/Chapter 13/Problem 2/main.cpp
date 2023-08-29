#include <iostream>

template <typename T>
class Node
{
public:
    // Node constructor to set Node -> next to null pointer
    Node() : next(nullptr){}
    T data;
    Node* next;
};

template <typename P>
class LinkedList
{
private:
    // private data members
    Node<P>* head;

    // private member functions
    // Finding middile point in Linked List and returning pointer to middle pointer in Linked List
    Node<P>* FindMiddle()
    {
        if (head == nullptr || head->next == nullptr){ return nullptr; }
        Node<P>* first = head;
        Node<P>* second = head;
        while (second != nullptr && second->next != nullptr)
        {
            first = first->next;
            second = second->next->next;
        }
        return first;
    }

    // Reversing the Linked List
    void ReverseLinkedList(Node<P>** headptr)
    {
        Node<P>* current = *headptr;
        Node<P>* next = nullptr;
        Node<P>* previous = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        *headptr = previous;
    }

public:
    // Constructor to set head pointer to null
    LinkedList() : head(nullptr) {}

    // Inserting values in Linked List at the start of Linked List
    void Push(P value)
    {
        Node<P>* node = new Node<P>();
        node->data = value;
        if (head == nullptr)
        {
            head = node;
            return;
        }
        node->next = head;
        head = node;
    }

    // Rearranging Linked List in L1 -> Ln -> L2 -> Ln-1 -> L3 -> Ln-2... order
    void RearrangeLinkedList()
    {
        if (head == nullptr || head->next == nullptr)
        {
            std::cout << "Not enough elements in the Linked List." << std::endl;
            return;
        }

        Node<P>* middle = FindMiddle();

        Node<P>* secondHalf = middle->next;
        middle->next = nullptr;

        ReverseLinkedList(&secondHalf);

        Node<P>* current1 = head;
        Node<P>* current2 = secondHalf;
        while(current2 != nullptr)
        {
            Node<P>* next1 = current1->next;
            Node<P>* next2 = current2->next;
            
            current1->next = current2;
            current2->next = next1;
            
            current1 = next1;
            current2 = next2;
        }
    }

    // Function to print Linked List starting from head pointer
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
    ll->Push(5);
    ll->Push(4);
    ll->Push(3);
    ll->Push(2);
    ll->Push(1);
    std::cout << "Before Rearranging:" << std::endl;
    ll->Print();
    ll->RearrangeLinkedList();
    std::cout << "After Rearranging:" << std::endl;
    ll->Print();
    return 0;
}
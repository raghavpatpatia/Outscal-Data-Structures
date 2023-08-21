#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node* next;
    ~Node()
    {
        std::cout << "Deleted Node-> " << data << std::endl;
    }
};

template <typename P>
class LinkedList
{
private:
    Node<P>* head;
public:
    LinkedList() : head(nullptr) {}
    void Insert(int pos, P value)
    {
        if (pos < 0)
        {
            std::cout << "Invalid position." << std::endl;
            return;
        }

        Node<P>* node = new Node<P>();
        node->data = value;
        node->next = nullptr;

        if (pos == 0)
        {  
            node->next = head;
            head = node;
            return;
        }
        
        Node<P>* current = head;
        for (int i = 0; current != nullptr && i < pos - 1; ++i)
        {
            current = current->next; 
        }

        if (current == nullptr)
        {
            std::cout << "Can not insert " << value << " at position " << pos << std::endl;
            std::cout << "Position out of bounds." << std::endl;
            return;
        }
        node->next = current->next;
        current->next = node;
    }
    void RemoveAt(int pos)
    {
        if (pos < 0)
        {
            std::cout << "Invalid position." << std::endl;
            return;
        }

        if (head == nullptr)
        {
            std::cout << "List is empty." << std::endl;
            return;
        } 

        Node<P>*current = head;
        
        if (pos == 0)
        {
            head = head->next;
            delete current;
            return;
        }
        
        Node<P>* prev = nullptr;
        for (int i = 0; current != nullptr && i < pos; ++i)
        {
            prev = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            std::cout << "Position out of bounds." << std::endl;
            return;
        }

        prev->next = current->next;
        delete current;
    }
    void Print()
    {
        Node<P>* node = head;
        int i = 0;
        while(node != nullptr)
        {
            std::cout << "Position: " << i << ", Node -> " << node->data << std::endl;
            i++;
            node = node->next;
        }
    }
};

int main()
{
    LinkedList<int>* ll = new LinkedList<int>();
    ll->Insert(0, 10);
    ll->Insert(1, 20);
    ll->Insert(2, 30);
    ll->Insert(3, 40);
    ll->Insert(1, 15);
    ll->Insert(0, 0);
    ll->Print();
    ll->RemoveAt(2);
    ll->Print();
    return 0;
}
#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class Node
{
public:
    Node() : next(nullptr) {}
    T data;
    Node* next;
};

template <typename P>
class Queue
{
private:
    Node<P>* front;
    Node<P>* rear;
    int size;
public:
    Queue() : rear(nullptr), front(nullptr), size(0){}
    void push(P value)
    {
        Node<P>* node = new Node<P>();
        node->data = value;
        if (empty())
        {
            rear = node;
            front = node;
        }
        else
        {
            rear->next = node;
            rear = node;
        }
        size++;
    }

    void pop()
    {
        if (empty()) 
        { 
            cout << "There are no elements inside the Queue." << endl;
            return; 
        }
        Node<P>* temp = front;
        front = front->next;
        delete temp;
        size--;
        if (front == nullptr)
        {
            rear = nullptr;
        }
    }

    P getFront()
    {
        if (empty()) { return P(); }
        return front->data;
    }

    int getSize()
    {
        return size;
    }

    bool empty()
    {
        return front == nullptr;
    }
};

int main()
{
    Queue<int>* queue = new Queue<int>();
    queue->push(10);
    queue->push(20);
    queue->push(30);
    queue->push(40);
    queue->push(50);
    cout << "Size of Queue after Inserting 10, 20, 30, 40, and 50: " << queue->getSize() << endl;
    cout << "Printing and removing elements from the Queue: " << endl;
    int i = 1;
    while (!queue->empty())
    {
        cout << "Printing element " << i << " of the Queue: " << queue->getFront() << endl;
        queue->pop();
        i++;
    }
    cout << "Size of the Queue after removing everything from the Queue: " << queue->getSize() << endl;
    delete queue;
    return 0;
}

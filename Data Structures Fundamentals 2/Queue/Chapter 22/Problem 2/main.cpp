#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class Node
{
public:
    Node() : next(nullptr){}
    T data;
    Node* next;
};

template <typename P>
class CircularQueue
{
private:
    Node<P>* front;
    Node<P>* rear;
    int currentSize;
public:
    CircularQueue() : front(nullptr), rear(nullptr), currentSize(0){}
    
    bool empty() { return currentSize == 0; }

    int size() { return currentSize; }

    void push(P value)
    {
        Node<P>* node = new Node<P>();
        node->data = value;
        if (empty())
        {
            node->next = node;
            front = rear = node;
        }
        else
        {
            node->next = front;
            rear->next = node;
            rear = node;
        }
        currentSize++;
    } 

    void pop()
    {
        if (empty())
        {
            cout << "Queue is empty can not remove anything." << endl;
            return;
        }
        if (currentSize == 1)
        {
            delete front;
            rear = front = nullptr;
        }
        else
        {
            Node<P>* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
        currentSize--;
    }

    P getFront()
    {
        if (empty())
        {
            cout << "Queue is empty." << endl;
            return P();
        }
        return front->data;
    }
    
    ~CircularQueue()
    {
        while (!empty())
        {
            pop();
        }
    }
};

int main()
{
    CircularQueue<int>* queue = new CircularQueue<int>();
    queue->push(10);
    queue->push(20);
    queue->push(30);
    queue->push(40);
    queue->push(50);
    cout << "Front element of queue is: " << queue->getFront() << endl;
    cout << "Size of the queue is: " << queue->size() << endl;
    cout << "Removing Front element..." << endl;
    queue->pop();
    cout << "Front element of queue is: " << queue->getFront() << endl;
    cout << "Size of the queue is: " << queue->size() << endl;
    delete queue;
    return 0;
}
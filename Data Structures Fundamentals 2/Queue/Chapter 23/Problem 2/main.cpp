#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    Node(T value, int prior) : data(value), priority(prior), next(nullptr) {}
    T data;
    int priority;
    Node* next;
};

template <typename T>
class PriorityQueue
{
private:
    Node<T>* front;
public:
    PriorityQueue() : front(nullptr){}
    void push(T value, int priority)
    {
        Node<T>* node = new Node<T>(value, priority);
        if (!front || priority > front->priority)
        {
            node->next = front;
            front = node;
        }
        else
        {
            Node<T>* current = front;
            while (current->next && priority <= current->next->priority)
            {
                current = current->next;
            }
            node->next = current->next;
            current->next = node;
        }
    }
    void pop()
    {
        if (!front)
        {
            cout << "Priority queue is empty. Cannot remove elements." << endl;
            return;
        }
        Node<T>* temp = front;
        front = front->next;
        delete temp;
    }
    T getFront()
    {
        if (!front)
        {
            cout << "Priority queue is empty." << endl;
            return T();
        }
        return front->data;
    }
    void print()
    {
        if (!front)
        {
            cout << "Priority queue is empty." << endl;
            return;
        }
        Node<T>* current = front;
        int i = 1;
        while (current)
        {
            cout << "Value of " << i << " element of Priority Queue is: " << current->data << endl;
            cout << "Value of " << i << " element's priority is: " << current->priority << endl;
            current = current->next;
            i++;
        }
    }
    ~PriorityQueue()
    {
        while (front)
        {
            pop();
        }
    }
};

int main()
{
    PriorityQueue<int>* pq = new PriorityQueue<int>();
    pq->push(10, 0);
    pq->push(20, 2);
    pq->push(30, 5);
    pq->push(40, 3);
    pq->push(50, 4);
    cout << "Front element of Priority Queue is: " << pq->getFront() << endl;
    cout << "Deleting front element..." << endl;
    pq->pop();
    cout << "Front element of Priority Queue is: " << pq->getFront() << endl;
    pq->print();
    delete pq;
    return 0;
}
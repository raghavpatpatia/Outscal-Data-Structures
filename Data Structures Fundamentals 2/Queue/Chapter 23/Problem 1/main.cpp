#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

enum Priorities
{
    Low = 1,
    Mid = 2,
    High = 3,
    Urgent = 4
};

template <typename T>
class Node
{
public:
    T data;
    Priorities priority;
};

template <typename T>
class PriorityQueue
{
private:
    Node<T>* arr;
    int front;
    int rear;
    int capacity;

    // Used string as we can also take input from user in console
    Priorities ConvertToPriority(const string& input)
    {
        if (input == "Low" || input == "low") return Low;
        if (input == "Mid" || input == "mid") return Mid;
        if (input == "High" || input == "high") return High;
        if (input == "Urgent" || input == "urgent") return Urgent;
        return Low;
    }

public:
    PriorityQueue(int size) : front(-1), rear(-1), capacity(size)
    {
        arr = new Node<T>[capacity];
    }

    void push(T value, string priority)
    {
        if (rear == capacity - 1)
        {
            cout << "Priority Queue is full. Cannot insert more elements." << endl;
            return;
        }
        Node<T> node;
        node.data = value;
        node.priority = ConvertToPriority(priority);
        int i;
        for (i = rear; i >= 0; --i)
        {
            if (node.priority > arr[i].priority)
            {
                arr[i + 1] = arr[i];
            }
            else
            {
                break;
            }
        }   
        arr[i + 1] = node;
        rear++;
    }

    void pop()
    {
        if (front + 1 == rear)
        {
            cout << "Priority queue is empty. Cannot pop." << endl;
            return;
        }
        front++;
    }

    T getFront()
    {
        if (front + 1 == rear)
        {
            cout << "Priority queue is empty." << endl;
            return T();
        }
        return arr[front + 1].data;
    }

    ~PriorityQueue()
    {
        delete[] arr;
    }
};

int main()
{
    PriorityQueue<int>* pq = new PriorityQueue<int>(10);
    pq->push(10, "low");
    pq->push(20, "high");
    pq->push(5, "mid");
    pq->push(7, "urgent");
    pq->push(3, "low");
    pq->push(15, "mid");
    cout << pq->getFront() << endl;
    pq->pop();
    cout << pq->getFront() << endl;
    pq->pop();
    cout << pq->getFront() << endl;
    pq->pop();
    cout << pq->getFront() << endl;
    pq->pop();
    cout << pq->getFront() << endl;
    delete pq;
    return 0;
}
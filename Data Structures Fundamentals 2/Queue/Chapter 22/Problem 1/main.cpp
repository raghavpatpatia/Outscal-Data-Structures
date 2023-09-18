#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class CircularQueue
{
private:
    T* arr;
    int front;
    int rear;
    int currentSize;
    int capacity;
public:
    CircularQueue(int size) : rear(-1), front(-1), currentSize(0), capacity(size)
    {
        arr =  new T[capacity];
    }

    bool empty() { return currentSize == 0; }

    bool full() { return currentSize == capacity; }

    int size() { return currentSize; }

    void push(T value)
    {
        if (full())
        {
            cout << "Queue is full can not push elements." << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        if (front == -1)
        {
            front = rear;
        }
        currentSize++;
    }

    void pop()
    {
        if (empty())
        {
            cout << "Queue is empty can not pop." << endl;
            return;
        }
        if (currentSize == 1)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        currentSize--;
    }

    T getFront()
    {
        if (empty())
        {
            cout << "Queue is empty." << endl;
            return T();
        }
        return arr[front];
    }

    ~CircularQueue()
    {
        delete[] arr;
    }
};

int main()
{
    CircularQueue<int>* queue = new CircularQueue<int>(5);
    cout << "Queue size: " << queue->size() << endl;
    cout << "Front element of queue is: " << queue->getFront();
    queue->push(10);
    queue->push(20);
    queue->push(30);
    queue->push(40);
    queue->push(50);
    cout << endl << "Inserted values 10, 20, 30, 40, and 50 in Queue." << endl;
    cout << "Queue size: " << queue->size() << endl;
    cout << "Front element of queue is: " << queue->getFront();
    cout << endl << "Inserting 60 in Queue." << endl;
    queue->push(60);
    cout << "Printing and removing all the elements inside the Queue." << endl;
    int i = 1;
    while (!queue->empty())
    {
        cout << "Element " << i << " of the queue: " << queue->getFront() << endl;
        queue->pop();
        i++;
    }
    queue->pop();
    cout << "Queue size: " << queue->size() << endl;
    delete queue;
    return 0;
}
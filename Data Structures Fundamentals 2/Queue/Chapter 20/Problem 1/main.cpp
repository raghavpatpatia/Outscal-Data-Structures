#include <iostream>
#define MAX_SIZE 100

using std::cout;
using std::endl;

template <typename T>
class Queue
{
private:
    T arr[MAX_SIZE];
    int frontIndex;
    int rearIndex;
public:
    Queue() : frontIndex(-1), rearIndex(-1) {}
    // Adding Elements in Queue
    void Push(T value)
    {
        if (rearIndex == MAX_SIZE - 1)
        {
            cout << "Queue is full. Cannot push element " << value << endl;
            return;
        }
        if (frontIndex == -1) {frontIndex = 0;}
        arr[++rearIndex] = value;
    }
    // Removing Elements in Queue
    void Pop()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot pop." << endl;
            return;
        }
        if (frontIndex == rearIndex)
        {
            frontIndex = -1;
            rearIndex = -1;
        }
        else
        {
            frontIndex++;
        }
    }
    // Returning the Element present at front of the Queue
    T Front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. There is no Front element." << endl;
            return -1;
        }
        return arr[frontIndex];
    }
    // Returns size of the queue
    int Size()
    {
        if (isEmpty()) { return 0; }
        return rearIndex - frontIndex + 1;
    }
    // Checks if Queue is Empty or not
    bool isEmpty()
    {
        return frontIndex == -1;
    }
};

int main()
{
    Queue<int>* queue = new Queue<int>();
    queue->Push(10);
    queue->Push(20);
    queue->Push(30);
    queue->Push(40);
    queue->Push(50);
    cout << "Front Element of the queue is: " << queue->Front() << endl;
    cout << "Queue size is: " << queue->Size() << endl;
    queue->Pop();
    cout << "After removing the front element." << endl;
    cout << "New front Element of the queue is: " << queue->Front() << endl;
    cout << "Queue size is: " << queue->Size() << endl;
    cout << "Is Queue Empty: " << (queue->isEmpty() ? "True" : "False") << endl;
    int i = 1;
    cout << endl << "...Printing Queue..." << endl;
    while (!queue->isEmpty())
    {
        cout << "Queue Element " << i << ": " << queue->Front() << endl;
        queue->Pop();
        i++;
    }
    delete queue;
    return 0;
}
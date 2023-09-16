#include <iostream>
#include <stack>
#include <memory>

using std::cout;
using std::endl;
using std::stack;
using std::unique_ptr;

template <typename T>
class Queue
{
private:
    unique_ptr<stack<T>> stack1 = std::make_unique<stack<T>>();
    unique_ptr<stack<T>> stack2 = std::make_unique<stack<T>>();
public:
    void push(T value)
    {
        stack1->push(value);
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        if (stack2->empty())
        {
            while (!stack1->empty())
            {
                stack2->push(stack1->top());
                stack1->pop();
            }
        }
        stack2->pop();
    }
    T getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return T();
        }
        if (stack2->empty())
        {
            while (!stack1->empty())
            {
                stack2->push(stack1->top());
                stack1->pop();
            }
        }
        return stack2->top();
    }
    bool isEmpty()
    {
        return stack1->empty() && stack2->empty();
    }
    int size()
    {
        return stack1->size() + stack2->size();
    }
};

int main()
{
    unique_ptr<Queue<int>> queue(new Queue<int>());
    queue->push(10);
    queue->push(20);
    queue->push(30);
    queue->push(40);
    queue->push(50);
    cout << "Size of Queue after Inserting 10, 20, 30, 40, and 50: " << queue->size() << endl;
    cout << "Printing and removing elements from the Queue: " << endl;
    int i = 1;
    while (!queue->isEmpty())
    {
        cout << "Printing element " << i << " of the Queue: " << queue->getFront() << endl;
        queue->pop();
        i++;
    }
    cout << "Size of the Queue after removing everything from the Queue: " << queue->size() << endl;
    return 0;
}
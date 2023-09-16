#include <iostream>
#include <list>
#include <memory>

using std::cout;
using std::endl;
using std::list;

template <typename T>
class Deque
{
private:
    list<T>* ll = new list<T>();
public:
    void push_front(T value)
    {
        ll->push_front(value);
    }
    void push_rear(T value)
    {
        ll->push_back(value);
    }
    void pop_front()
    {
        if (isEmpty())
        {
            cout << "Deque is empty. Can not remove from front." << endl;
            return;
        }
        else
        {
            ll->pop_front();
        }
    }
    void pop_rear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty. Can not remove from the rear." << endl;
            return;
        }
        else
        {
            ll->pop_back();
        }
    }
    T getFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty." << endl;
            return T();
        }
        return ll->front();
    }
    T getRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty." << endl;
            return T();
        }
        return ll->back();
    }
    bool isEmpty()
    {
        return ll->empty();
    }
    ~Deque()
    {
        delete ll;
    } 
};

int main()
{
    std::unique_ptr<Deque<int>> deque(new Deque<int>());
    deque->push_rear(10);
    deque->push_rear(20);
    deque->push_rear(30);
    deque->push_rear(40);
    deque->push_front(5);
    deque->push_front(0);
    cout << "Front element of Deque: " << deque->getFront() << endl;
    cout << "Rear element of Deque: " << deque->getRear() << endl;
    deque->pop_front();
    deque->pop_rear();
    cout << "After removing front and rear element from Deque..." << endl;
    cout << "Front element of Deque: " << deque->getFront() << endl;
    cout << "Rear element of Deque: " << deque->getRear() << endl;
    int i = 1;
    while (!deque->isEmpty())
    {
        cout << "Element " << i << " from front of the Deque is: " << deque->getFront() << endl;
        deque->pop_front(); 
        i++;
    }
    return 0;
}
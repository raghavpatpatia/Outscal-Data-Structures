#include <iostream>
#define MAX_SIZE 100

using std::cout;
using std::endl;

template <typename T>
class Deque
{
private:
    T arr[MAX_SIZE];
    int frontIndex;
    int rearIndex;

    //Checks if Deque is full
    bool isFull()
    {
        return (frontIndex == 0 && rearIndex == MAX_SIZE - 1) || (frontIndex == rearIndex + 1);
    }
public:
    Deque() : frontIndex(-1), rearIndex(-1) {}
    // Checks if Deque is Empty or not
    bool isEmpty()
    {
        return frontIndex == -1;
    }
    // Adding Elements at front of Deque
    void InsertFront(T value)
    {
        if (isFull())
        {
            cout << "Deque is full. Cannot insert element " << value << " at the front." << endl;
            return;
        }
        if (isEmpty()) 
        {
            frontIndex = 0;
            rearIndex = 0;
        }
        else if (frontIndex == 0)
        {
            frontIndex = MAX_SIZE - 1;
        }
        else
        {
            frontIndex--;
        }
        arr[frontIndex] = value;
    }
    // Adding Elements at rear of Deque
    void InsertRear(T value)
    {
        if (isFull())
        {
            cout << "Deque is full. Cannot insert element " << value << " at the rear." << endl;
            return;
        }
        if (isEmpty()) 
        {
            frontIndex = 0;
            rearIndex = 0;
        }
        else if (rearIndex == MAX_SIZE - 1)
        {
            rearIndex = 0;
        }
        else
        {
            rearIndex++;
        }
        arr[rearIndex] = value;
    }
    // Removing Elements from front of Deque
    void DeleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty. Can not delete from front." << endl;
            return;
        }
        if (frontIndex == rearIndex)
        {
            frontIndex = -1;
            rearIndex = -1;
        }
        else if (frontIndex == MAX_SIZE - 1)
        {
            frontIndex = 0;
        }
        else
        {
            frontIndex++;
        }
    }
    // Removing Elements from the rear of Deque
    void DeleteRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty. Can not delete from the rear of Deque." << endl;
            return;
        }
        if (frontIndex == rearIndex)
        {
            frontIndex = -1;
            rearIndex = -1;
        }
        else if (rearIndex == 0)
        {
            rearIndex = MAX_SIZE - 1;
        }
        else
        {
            rearIndex--;
        }
    }
    // returns front element in Deque
    T GetFront()
    {
        if (isEmpty())
        {
            cout << "Deque is Empty." << endl;
            return -1;
        }
        return arr[frontIndex];
    }
    // returns rear element in Deque
    T GetRear()
    {
        if (isEmpty())
        {
            cout << "Deque is Empty." << endl;
            return -1;
        }
        return arr[rearIndex];
    }
};

int main()
{
    Deque<int>* deque = new Deque<int>();
    deque->InsertFront(40);
    deque->InsertFront(30);
    deque->InsertFront(20);
    deque->InsertFront(10);
    deque->InsertRear(50);
    deque->InsertRear(60);
    deque->InsertRear(70);
    deque->InsertRear(80);
    cout << "Front element of Deque: " << deque->GetFront() << endl;
    cout << "Rear element of Deque: " << deque->GetRear() << endl;
    deque->DeleteFront();
    deque->DeleteRear();
    cout << "After deleting front and rear element in Deque..." << endl;
    cout << "Front element of Deque: " << deque->GetFront() << endl;
    cout << "Rear element of Deque: " << deque->GetRear() << endl;
    cout << "Is Deque empty: " << (deque->isEmpty() ? "True" : "False") << endl;
    cout << endl << "... Printing Deque ..." << endl;
    int i = 1;
    while (!deque->isEmpty())
    {
        cout << "Printing element " << i << " from the front of the Deque: " << deque->GetFront() << endl;
        deque->DeleteFront();
        i++;
    }
    delete deque;
    return 0;
}
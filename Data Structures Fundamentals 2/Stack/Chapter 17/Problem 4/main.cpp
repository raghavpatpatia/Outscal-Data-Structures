#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

template <typename T>
class Stack
{
private:
    static const int Max_Size = 100;
    T data[Max_Size];
    int top;
    int mid;

public:
    Stack() : top(-1), mid(-1) {}
    
    void Push(T value)
    {
        if (top >= Max_Size - 1)
        {
            throw std::overflow_error("Stack is full.");
        }
        data[++top] = value;
        mid = (top + 1) / 2;
    }

    void Pop()
    {
        if (IsEmpty())
        {
            throw std::underflow_error("Stack is empty.");
        }
        --top;
        mid = (top + 1) / 2;
    }

    T Peek()
    {
        if (IsEmpty())
        {
            throw std::underflow_error("Stack is empty.");
        }
        return data[top];
    }

    T Middle()
    {
        if (IsEmpty())
        {
            throw std::underflow_error("Stack is empty.");
        }
        return data[mid];
    }

    void DeleteMiddle()
    {
        if (IsEmpty())
        {
            throw std::underflow_error("Stack is empty.");
        }
        for (int i = mid; i < top; i++)
        {
            data[i] = data[i + 1];
        }
        top--;
        mid = (top + 1) / 2;
    }

    bool IsEmpty()
    {
        return top == -1;
    }
};

int main()
{
    Stack<int> stack;
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);
    cout << "Middle Element in stack: " << stack.Middle() << endl;
    stack.DeleteMiddle();
    cout << "Middle Element in stack: " << stack.Middle() << endl;
    cout << "Top Element in stack: " << stack.Peek() << endl;
    stack.Pop();
    cout << "Top Element in stack: " << stack.Peek() << endl;
    cout << "Middle Element in stack: " << stack.Middle() << endl;
    cout << "Is Stack Empty: " << (stack.IsEmpty() ? "true" : "false") << endl;
    stack.Pop();
    stack.Pop();
    stack.Pop();
    cout << "Is Stack Empty: " << (stack.IsEmpty() ? "true" : "false") << endl;
    return 0;
}

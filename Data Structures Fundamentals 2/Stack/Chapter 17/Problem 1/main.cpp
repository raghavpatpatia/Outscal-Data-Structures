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

public:
    Stack() : top(-1) {}
    
    void Push(T value)
    {
        if (top >= Max_Size - 1)
        {
            throw std::overflow_error("Stack is full.");
        }
        data[++top] = value;
    }

    void Pop()
    {
        if (IsEmpty())
        {
            throw std::underflow_error("Stack is empty.");
        }
        --top;
    }

    T Peek()
    {
        if (IsEmpty())
        {
            throw std::underflow_error("Stack is empty.");
        }
        return data[top];
    }

    bool IsEmpty()
    {
        return top == -1;
    }
};

int main()
{
    Stack<int>* stack = new Stack<int>();
    stack->Push(30);
    stack->Push(20);
    stack->Push(10);
    stack->Push(0);
    cout << "Top Element in stack: " << stack->Peek() << endl;
    stack->Pop();
    cout << "Top Element in stack: " << stack->Peek() << endl;
    stack->Pop();
    cout << "Is Stack Empty: " << (stack->IsEmpty() ? "true" : "false") << endl;
    stack->Pop();
    stack->Pop();
    cout << "Is Stack Empty: " << (stack->IsEmpty() ? "true" : "false") << endl;
    delete stack;
    return 0;
}
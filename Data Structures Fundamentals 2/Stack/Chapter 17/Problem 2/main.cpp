#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

template <typename T>
class TwoStacks
{
private:
    static const int Max_Size = 100;
    T data[Max_Size];
    int top1;
    int top2;

public:
    TwoStacks() : top1(-1), top2(Max_Size) {}
    
    void Push1(T value)
    {
        if (top1 + 1 == top2)
        {
            throw std::overflow_error("Stack 1 is full.");
        }
        data[++top1] = value;
    }

    void Push2(T value)
    {
        if (top2 - 1 == top1)
        {
            throw std::overflow_error("Stack 2 is full.");
        }
        data[--top2] = value;
    }

    void Pop1()
    {
        if (IsEmpty1())
        {
            throw std::underflow_error("Stack 1 is empty.");
        }
        --top1;
    }

    void Pop2()
    {
        if (IsEmpty2())
        {
            throw std::underflow_error("Stack 2 is empty.");
        }
        ++top2;
    }

    T Peek1()
    {
        if (IsEmpty1())
        {
            throw std::underflow_error("Stack 1 is empty.");
        }
        return data[top1];
    }

    T Peek2()
    {
        if (IsEmpty2())
        {
            throw std::underflow_error("Stack 2 is empty.");
        }
        return data[top2];
    }

    bool IsEmpty1()
    {
        return top1 == -1;
    }

    bool IsEmpty2()
    {
        return top2 == Max_Size;
    }
};

int main()
{
    TwoStacks<int>* twoStacks = new TwoStacks<int>();
    twoStacks->Push1(10);
    twoStacks->Push2(20);
    twoStacks->Push1(30);
    twoStacks->Push2(40);

    cout << "Top element of Stack 1: " << twoStacks->Peek1() << endl;
    cout << "Top element of Stack 2: " << twoStacks->Peek2() << endl;

    twoStacks->Pop1();
    twoStacks->Pop2();

    cout << "Popped elements from Stack 1 and Stack 2." << endl;

    cout << "Top element of Stack 1: " << twoStacks->Peek1() << endl;
    cout << "Top element of Stack 2: " << twoStacks->Peek2() << endl;

    cout << "Is Stack 1 Empty: " << (twoStacks->IsEmpty1() ? "true" : "false") << endl;
    cout << "Is Stack 2 Empty: " << (twoStacks->IsEmpty2() ? "true" : "false") << endl;

    twoStacks->Pop1();
    twoStacks->Pop2();
    cout << "Popped elements from Stack 1 and Stack 2." << endl;

    cout << "Is Stack 1 Empty: " << (twoStacks->IsEmpty1() ? "true" : "false") << endl;
    cout << "Is Stack 2 Empty: " << (twoStacks->IsEmpty2() ? "true" : "false") << endl;
    return 0;
}
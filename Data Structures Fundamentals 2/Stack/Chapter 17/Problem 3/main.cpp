#include <iostream>
#include <string>
#include <stdexcept>

using std::cout;
using std::endl;
using std::string;

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

class Solution
{
private:
    bool IsOperator(char ch)
    {
        switch (ch)
        {
            case '+':
            case '-':
            case '/':
            case '*':
            case '^':
            case '%':
                return true;
            default:
                return false;
        }
    }
public:
    string PrefixtoInfix(string prefix)
    {
        Stack<string>* operands = new Stack<string>();
        int length = prefix.length();
        for (int i = length - 1; i >= 0; i--)
        {
            if (IsOperator(prefix[i]))
            {
                string operand1 = operands->Peek();
                operands->Pop();
                string operand2 = operands->Peek();
                operands->Pop();
                string temp = "(" + operand1 + prefix[i] + operand2 + ")";
                operands->Push(temp);
            }
            else
            {
                operands->Push(string(1, prefix[i]));
            }
        }
        string infix = operands->Peek();
        delete operands;
        return infix;
    }
};

int main()
{
    string prefix;
    Solution solution;
    cout << "Enter your expression: ";
    std::getline(std::cin, prefix);
    cout << "Your Infix expression: " << solution.PrefixtoInfix(prefix) << endl;
    return 0;
}
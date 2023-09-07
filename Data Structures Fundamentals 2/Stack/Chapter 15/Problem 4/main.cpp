#include <iostream>
#include <string>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <typename T>
class Node
{
public:
    T data;
    Node* next;
};

template <typename P>
class LinkedList
{
private:
    Node<P>* head;
public:
    LinkedList() : head(nullptr) {}
    void Push(P value)
    {
        Node<P>* node = new Node<P>();
        node->data = value;
        node->next = nullptr;
        if (head == nullptr)
        {
            head = node;
            return;
        }
        node->next = head;
        head = node;
    }
    Node<P>* GetHead()
    {
        return head;
    }
    void Pop()
    {
        if (head)
        {
            Node<P>* node = head;
            head = head->next;
            delete node;
        }
    }
    ~LinkedList()
    {
        while (head != nullptr)
        {
            Node<P>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

template <typename R>
class Stack
{
private:
    LinkedList<R> ll;
public:

    void Push (R value)
    {
        ll.Push(value);
    }
    void Pop()
    {
        ll.Pop();
    }
    R Peek()
    {
        Node<R>* peek = ll.GetHead();
        if (peek)
        {
            return peek->data;
        }
        throw std::out_of_range("Stack is empty.");
    }
    bool IsEmpty ()
    {
        return !ll.GetHead();
    }
};

class Solution
{
private:
    
    int Precedence(char ch)
    {
        switch (ch)
        {
            case '^':
                return 3;
            case '/':
            case '*':
                return 2;
            case '+':
            case '-':
                return 1;
            default:
                return -1;            
        }
    }

public:
    
    void InfixtoPostfix(string infix)
    {
        Stack<char> st;
        string result;
        try
        {
            for (int i = 0; i < infix.length(); i++)
            {
                char ch = infix[i];

                if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
                    result += ch;
                
                else if (ch == '(')
                    st.Push(ch);
                
                else if (ch == ')')
                {
                    while (st.Peek() != '(')
                    {   
                        result += st.Peek();
                        st.Pop();
                    }
                    st.Pop();
                }

                else
                {
                    while (!st.IsEmpty() && Precedence(infix[i]) <= Precedence(st.Peek()))
                    {
                        result += st.Peek();
                        st.Pop();
                    }
                    st.Push(ch);
                }
            }

            while (!st.IsEmpty())
            {
                result += st.Peek();
                st.Pop();
            }
            cout << result << endl;
        }
        catch (std::out_of_range& e)
        {
            cout << "Invalid expression: Mismatched parentheses" << endl;
        }
    }
};

int main()
{
    string infixExpression;
    Solution solution;
    cout << "Enter your infix expression: ";
    getline(cin, infixExpression);
    solution.InfixtoPostfix(infixExpression);
    return 0;
}
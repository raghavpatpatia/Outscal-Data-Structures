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
public:
    bool isBalanced (string expression)
    {
        Stack<char> stack;
        for (int i = 0; i < expression.length(); i++)
        {
            if (expression[i] == '(')
            {
                stack.Push(expression[i]);
            }
            else if (expression[i] == ')')
            {
                if (stack.IsEmpty()) return false;
                stack.Pop();
            }
        }
        return stack.IsEmpty();
    }
};

int main()
{
    string expression;
    Solution solution;
    cout << "Enter your expression: ";
    getline(cin, expression);
    cout << "Is Expression balanced: " << (solution.isBalanced(expression) ? "true" : "false") << endl;
    return 0;
}
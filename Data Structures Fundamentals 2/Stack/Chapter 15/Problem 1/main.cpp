#include <iostream>

using std::cout;
using std::endl;

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
        while (!head)
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

int main()
{
    Stack<int>* stack = new Stack<int>();
    stack->Push(50);
    stack->Push(40);
    stack->Push(30);
    stack->Push(20);
    stack->Push(10);
    // Deleting an element inside stack
    stack->Pop();
    // Printing stack
    while (!stack->IsEmpty())
    {
        // Printing the top element
        cout << stack->Peek() << endl;
        stack->Pop();
    }
    // Checking if stack is empty or not
    cout << (stack->IsEmpty() ? "true" : "false") << endl;

    stack->Push(10);
    cout << (stack->IsEmpty() ? "true" : "false") << endl;
    return 0;
}
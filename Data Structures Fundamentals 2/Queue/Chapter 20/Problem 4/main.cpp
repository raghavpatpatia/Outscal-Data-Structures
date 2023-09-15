#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class Stack {
private:
    queue<int> primaryQueue;
    queue<int> secondaryQueue;

public:
    void push(T x) {
        // Move all elements from primaryQueue to secondaryQueue
        while (!primaryQueue.empty()) {
            secondaryQueue.push(primaryQueue.front());
            primaryQueue.pop();
        }

        // Add the new element to the empty primaryQueue
        primaryQueue.push(x);

        // Move elements back from secondaryQueue to primaryQueue
        while (!secondaryQueue.empty()) {
            primaryQueue.push(secondaryQueue.front());
            secondaryQueue.pop();
        }
    }

    void pop() {
        if (empty()) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return;
        }
        primaryQueue.pop();
    }

    T peek() {
        if (empty()) {
            std::cout << "Stack is empty. No top element." << std::endl;
            return -1; 
        }
        return primaryQueue.front();
    }

    bool empty() {
        return primaryQueue.empty();
    }
};

int main() {
    Stack<int>* stack = new Stack<int>();
    stack->push(10);
    stack->push(20);
    stack->push(30);

    std::cout << "Top element: " << stack->peek() << std::endl;

    stack->pop();
    std::cout << "After removing the top element." << std::endl;
    std::cout << "Top element: " << stack->peek() << std::endl;
    delete stack;

    return 0;
}

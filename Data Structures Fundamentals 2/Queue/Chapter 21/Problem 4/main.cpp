#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template <typename T>
class Solution
{
private:
    stack<T> stack1;
public:
    void ReverseQueue(queue<T> &queue1)
    {
        if (queue1.empty()) 
        { 
            cout << "Queue is empty." << endl;
            return;
        }
        while (!queue1.empty())
        {
            stack1.push(queue1.front());
            queue1.pop();
        }
        while (!stack1.empty())
        {
            queue1.push(stack1.top());
            stack1.pop();
        }
    }
};

int main()
{
    queue<int> queue1;
    queue<int> queue2;
    Solution<int> solution;
    queue1.push(10);
    queue1.push(20);
    queue1.push(30);
    queue1.push(40);
    queue1.push(50);

    cout << "Original Queue: ";
    while (!queue1.empty())
    {
        cout << queue1.front() << " ";
        queue2.push(queue1.front());
        queue1.pop();
    }

    solution.ReverseQueue(queue2);

    cout << endl << "Reversed Queue: ";
    while (!queue2.empty())
    {
        cout << queue2.front() << " ";
        queue2.pop();
    }
    return 0;
}
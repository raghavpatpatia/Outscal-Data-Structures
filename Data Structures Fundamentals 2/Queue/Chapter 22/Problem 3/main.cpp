#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class Solution
{
public:
    queue<T> Reverse(queue<T> queue1)
    {
        queue<T> reversedQueue;
        int size = queue1.size();
        for (int i = 0; i < size; i++) 
        {
            for (int j = 0; j < queue1.size() - 1; j++) 
            {
                queue1.push(queue1.front());
                queue1.pop();
            }
            reversedQueue.push(queue1.front());
            queue1.pop();
        }
        return reversedQueue;
    }
};

int main()
{
    int size;
    int value;
    Solution<int> solution;
    queue<int> queue1;
    cout << "Enter size for the queue: ";
    cin >> size;
    for (int i = 1; i <= size; i++)
    {
        cout << "Enter element " << i << " in queue: ";
        cin >> value;
        queue1.push(value);
    }
    queue<int> reversedQueue = solution.Reverse(queue1);
    cout << "Original Queue: ";
    while (!queue1.empty())
    {
        cout << queue1.front() << " ";
        queue1.pop();
    }
    cout << endl << "Reversed Queue: ";
    while (!reversedQueue.empty())
    {
        cout << reversedQueue.front() << " ";
        reversedQueue.pop();
    }
    return 0;
}
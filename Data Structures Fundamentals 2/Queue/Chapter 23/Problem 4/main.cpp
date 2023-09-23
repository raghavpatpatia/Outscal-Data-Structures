#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
    void KthSmallestElement (int arr[], int size, int k)
    {
        priority_queue<int> pq;
        if (k > 0 && k <= size)
        {
            for (int i = 0; i < size; i++)
            {
                pq.push(arr[i]);
                if (pq.size() > k)
                {
                    pq.pop();
                }
            }
            cout << "Kth smallest element is: " << pq.top();
        }
        else
        {
            cout << "Invalid value for K" << endl;
        }
    }
};

int main() 
{
    int size;
    cout << "Enter number of elements you want to store in the array: ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << " of array: ";
        cin >> arr[i];
    }
    int k;
    cout << "Enter value of K: ";
    cin >> k;
    Solution solution;
    solution.KthSmallestElement(arr, size, k);
    return 0;
}

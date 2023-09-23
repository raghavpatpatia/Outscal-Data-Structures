#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
    void SortedArray (int arr[], int size)
    {
        priority_queue<int> pq;
        for (int i = 0; i < size; i++)
        {
            pq.push(arr[i]);
        }
        for (int i = size - 1; i >= 0; i--)
        {
            arr[i] = pq.top();
            pq.pop();
        }
        cout << "Sorted Array: " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "Element " << i + 1 << " of Array: " << arr[i] << endl;
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
    Solution solution;
    solution.SortedArray(arr, size);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Complete this function
vector<int> FindMultiplication(vector<int>& arr)
{
    int size = arr.size();
    vector<int> result(size, -1);
    priority_queue<int> pq;
    for (int i = 0; i < size; i++)
    {
        pq.push(arr[i]);
        if (i >= 2)
        {
            int firstTop = pq.top();
            pq.pop();
            int secondTop = pq.top();
            pq.pop();
            int thirdTop = pq.top();
            pq.pop();
            result[i] = firstTop * secondTop * thirdTop;
            pq.push(firstTop);
            pq.push(secondTop);
            pq.push(thirdTop);
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &e : arr)
        cin >> e;
    auto ans = FindMultiplication(arr);
    for (auto e : ans)
        cout << e << '\n';
}


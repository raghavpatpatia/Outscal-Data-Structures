#include <bits/stdc++.h>
using namespace std;

int shortestSubarray(int nums[], int k, int n) 
{
  vector<int> prefixSum(n + 1, 0);
  deque<int> dq;
  for (int i = 0; i < n; i++)
  {
    prefixSum[i + 1] = prefixSum[i] + nums[i];
  }
  int minLength = n + 1;
  for (int i = 0; i <= n; i++)
  {
    while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k)
    {
      minLength = min(minLength, i - dq.front());
      dq.pop_front();
    }
    while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()])
    {
      dq.pop_back();
    }
    dq.push_back(i);
  }
  return (minLength <= n) ? minLength : -1;
}

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION 
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED 
//***********************************

int main() {
  int size , k;
  cin>>size;
  int arr[size];
  for(int i =0;i<size;i++){
    cin>>arr[i];
  }
  cin>>k;
  int ans = shortestSubarray(arr,k, size);
  cout<<ans;
}
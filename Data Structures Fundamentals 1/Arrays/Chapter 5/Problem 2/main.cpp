#include <bits/stdc++.h>
using namespace std;
class Outscal {
public:
  int maximum(int nums[], int size) {
    int profit = 0;
    int buy = nums[0];
    for (int i = 0; i < size; i++)
    {
        if(buy > nums[i])
            buy = nums[i];
        
        else if(nums[i] - buy > profit)
            profit = nums[i] - buy;
    }
    return profit;
  }
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED
//***********************************

int main() {
  int size;
  cin >> size;
  int arr[size];
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }
  class Outscal s;
  cout << s.maximum(arr, size);
}
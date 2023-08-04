#include <iostream>
using namespace std;
class Outscal {
public:
    int trap(int nums[], int size) {
        int left = 0, right = size - 1;
        int leftMax = 0, rightMax = 0;
        int totalWater = 0;
        while (left <= right)
        {
            if (leftMax <= rightMax)
            {
                totalWater += max(0, leftMax - nums[left]);
                leftMax = max(leftMax, nums[left]);
                left++;
            }
            else
            {
                totalWater += max(0, rightMax - nums[right]);
                rightMax = max(rightMax, nums[right]);
                right--;
            }
        }
        return totalWater;
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
  cout << s.trap(arr, size);
}
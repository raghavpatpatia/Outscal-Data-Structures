#include <iostream>
#include <algorithm>
using namespace std;
class Outscal {
public:
    /*
    ---divide and conquer approach---
    int maxCrossingSum(int nums[], int low, int mid, int high) {
        int leftSum = INT_MIN;
        int sum = 0;

        for (int i = mid; i >= low; i--) {
            sum += nums[i];
            if (sum > leftSum)
                leftSum = sum;
        }

        int rightSum = INT_MIN;
        sum = 0;

        for (int i = mid + 1; i <= high; i++) {
            sum += nums[i];
            if (sum > rightSum)
                rightSum = sum;
        }

        return leftSum + rightSum;
    }

    int maxSubarraySum(int nums[], int low, int high) {
        if (low == high)
            return nums[low];

        int mid = (low + high) / 2;

        int leftSum = maxSubarraySum(nums, low, mid);
        int rightSum = maxSubarraySum(nums, mid + 1, high);
        int crossingSum = maxCrossingSum(nums, low, mid, high);

        return max({leftSum, rightSum, crossingSum});
    }

    int maximumSubarray(int nums[], int size) {
        return maxSubarraySum(nums, 0, size - 1);
    }
    */
    int maximumSubarray(int nums[], int size) {
        int currentMax = nums[0];
        int maxTillNow = nums[0];
        for (int i = 1; i < size; i++)
        {
            currentMax = max(nums[i], currentMax + nums[i]);
            maxTillNow = max(maxTillNow, currentMax);
        }
        return maxTillNow;
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
  cout << s.maximumSubarray(arr, size);
}
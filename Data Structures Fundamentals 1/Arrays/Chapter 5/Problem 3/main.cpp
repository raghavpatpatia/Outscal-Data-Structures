#include <bits/stdc++.h>
using namespace std;
class Outscal {
public:
    void merge(int nums1[], int nums2[], int size1, int size2) {
        int n = size1 + size2;
        int arr[n];
        int indexNums1 = 0;
        int indexNums2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (indexNums1 < size1)
            {
                if ((nums1[indexNums1] > nums2[indexNums2]) && (indexNums2 < size2))
                {
                    arr[i] = nums2[indexNums2];
                    indexNums2++;
                }
                else
                {
                    arr[i] = nums1[indexNums1];
                    indexNums1++;
                }
            }
            else
            {
                arr[i] = nums2[indexNums2];
                indexNums2++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED
//***********************************

int main() {
  int size1;
  cin >> size1;
  int nums1[size1];
  for (int i = 0; i < size1; i++) {
    cin >> nums1[i];
  }
  int size2;
  cin >> size2;
  int nums2[size2];
  for (int i = 0; i < size2; i++) {
    cin >> nums2[i];
  }
  class Outscal s;
  s.merge(nums1, nums2, size1, size2);
}
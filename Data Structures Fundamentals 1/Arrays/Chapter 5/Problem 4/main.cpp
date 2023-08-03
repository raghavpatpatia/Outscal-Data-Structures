#include <bits/stdc++.h>
using namespace std;
void longestConsecutive(int arr[], int size) {
    sort(arr, arr + size);
    int curLen = 1, mxLen = 1;
    for(int i = 0; i < size; i++)
        if(arr[i] == arr[i + 1] - 1)
        curLen += 1,
        mxLen = (mxLen > curLen) ? mxLen : curLen;
        else
        curLen = 1;
    cout << mxLen;
}

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
  longestConsecutive(arr, size);
}
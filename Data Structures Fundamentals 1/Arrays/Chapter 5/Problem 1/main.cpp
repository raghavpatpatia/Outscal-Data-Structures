#include <bits/stdc++.h>
#include <set>
#include <array>
#include <algorithm>
using namespace std;
class Outscal {
public:     
    void maximum(int nums[],int size) 
    {
        sort(nums, nums + size);
        set<array<int, 3>> result;
        int left, right;
        for (int i = 0; i < size - 3; i++)
        {
            left = i + 1;
            right = size - 1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    array<int, 3> temp = {nums[i], nums[left], nums[right]};
                    result.insert(temp);
                    left++;
                }
                else if (sum > 0)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            } 
        }
        for (auto it = result.rbegin(); it != result.rend(); it++)
        {
            cout << (*it).at(0) << " " << (*it).at(1) << " " << (*it).at(2) << endl;
        }
    }
         
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION 
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED 
//***********************************

int main() {
    int size;
    cin>>size;
    int arr[size];
    for(int i =0;i<size;i++){
    cin>>arr[i];
    }
    class Outscal s;
    s.maximum(arr,size);
  
}
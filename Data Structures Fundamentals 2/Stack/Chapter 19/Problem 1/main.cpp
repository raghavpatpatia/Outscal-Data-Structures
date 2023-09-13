#include<bits/stdc++.h> 
using namespace std; 

class Outscal {
  public: 
    vector<int> commonPrefix (vector<int> nums1,vector<int> nums2) { 
	   //Write your code here
        unordered_map<int, int> nextGreaterMap; 
        stack<int> nextGreaterStack;
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!nextGreaterStack.empty() && nums2[i] >= nextGreaterStack.top())
            {
                nextGreaterStack.pop();
            }
            if (nextGreaterStack.empty())
            {
                nextGreaterMap[nums2[i]] = -1;
            }
            else
            {
                nextGreaterMap[nums2[i]] = nextGreaterStack.top();
            }
            nextGreaterStack.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            nums1[i] = nextGreaterMap[nums1[i]];
        }
        return nums1;
    }
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION 
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED 
//***********************************

int main() 
{ 
  int m,temp,i,n;
  vector <int> brr,arr;
  cin>>m>>n;
  while(m)
  {
    cin>>temp;
    brr.push_back(temp);
    m--;
  }
  while(n)
  {
    cin>>temp;
    arr.push_back(temp);
    n--;
  }
  class Outscal s;
	vector<int> ans = s.commonPrefix(brr,arr); 
  for(i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
	return (0); 
} 

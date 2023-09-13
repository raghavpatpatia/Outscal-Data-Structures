#include<bits/stdc++.h> 
using namespace std; 

class Outscal {
  public: 
    bool find132pattern(vector<int> nums) { 
	    //Write your code here
        int max_2 = INT_MIN;
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] < max_2) 
            {
                return true;
            }
            
            while (!st.empty() && nums[i] > st.top()) 
            {
                max_2 = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    } 
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION 
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED 
//***********************************

int main() 
{ 
  int m;
  int temp;
  vector <int> brr;
  cin>>m;
  while(m)
  {
    cin>>temp;
    brr.push_back(temp);
    m--;
  }
  class Outscal s;
	bool ans = s.find132pattern(brr); 
	if (ans) 
		cout<<"True"; 
	else
		cout<<"False";
	return (0); 
} 

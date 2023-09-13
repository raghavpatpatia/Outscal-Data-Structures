#include<bits/stdc++.h> 
using namespace std; 

class Outscal {
  public: 
    int largestRectangleArea (vector<int> histogram) { 
	   //Write your code here
        int n = histogram.size();
        int maxArea = 0;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && histogram[i] < histogram[st.top()])
            {
                int height = histogram[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        while(!st.empty())
        {
           int height = histogram[st.top()];
            st.pop();
            int width = st.empty() ? n : n - st.top() - 1;
            maxArea = max(maxArea, height * width); 
        }
        return maxArea;
    } 
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION 
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED 
//***********************************

int main() 
{ 
  int m,temp;
  vector <int> brr;
  cin>>m;
  while(m)
  {
    cin>>temp;
    brr.push_back(temp);
    m--;
  }
  class Outscal s;
	int ans = s.largestRectangleArea(brr); 
	cout<<ans;
	return (0); 
} 

#include<bits/stdc++.h> 
using namespace std; 

class Outscal {
  public: 
    vector<int> asteroidCollision(vector<int> asteroids) { 
	    //Write your code here
        stack<int> survivors;
        for (int i = 0; i < asteroids.size(); i++)
        {
            int asteroid = asteroids[i];
            if (asteroid > 0 || survivors.empty())
            {
                survivors.push(asteroid);
            }
            else
            {
                while (!survivors.empty() && survivors.top() > 0 && survivors.top() < -asteroid)
                {
                    survivors.pop();
                }
                if (survivors.empty() || survivors.top() < 0)
                {
                    survivors.push(asteroid);
                }
                else if (survivors.top() == -asteroid)
                {
                    survivors.pop();
                }
            }
        }
        
        vector<int> result(survivors.size());
        for (int i = survivors.size() - 1; i >= 0; i--) 
        {
            result[i] = survivors.top();
            survivors.pop();
        }
        return result;
    } 
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION 
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED 
//***********************************

int main() 
{ 
  int m,i,temp;
  vector <int> brr;
  cin>>m;
  while(m)
  {
    cin>>temp;
    brr.push_back(temp);
    m--;
  }
  class Outscal s;
	vector<int> ans = s.asteroidCollision(brr); 
	for(i=0;i<ans.size();i++)
	  cout<<ans[i]<<" ";
	return (0); 
} 

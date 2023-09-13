#include<bits/stdc++.h> 
using namespace std; 

class Outscal {
  public: 
    int game(vector<string> ops) { 
	    //Write your code here
        stack<int> validScore;
        int sum = 0;
        for (int i = 0; i < ops.size(); i++)
        {
            string op = ops[i];
            if (isdigit(op[0]) || (op[0] == '-' && isdigit(op[1])))
            {
                validScore.push(stoi(op));
            }
            else if (op == "+")
            {
                int top = validScore.top();
                validScore.pop();
                int newScore = top + validScore.top();
                validScore.push(top);
                validScore.push(newScore);
            }
            else if (op == "D")
            {
                validScore.push(2 * validScore.top());
            }
            else if (op == "C")
            {
                validScore.pop();
            }
        }
        while (!validScore.empty())
        {
            sum += validScore.top();
            validScore.pop();
        }
        return sum;
    } 
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION 
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED 
//***********************************

int main() 
{ 
  int m;
  string temp;
  vector <string> brr;
  cin>>m;
  while(m)
  {
    cin>>temp;
    brr.push_back(temp);
    m--;
  }
  class Outscal s;
	int ans = s.game(brr); 
	cout<<ans;
	return (0); 
} 


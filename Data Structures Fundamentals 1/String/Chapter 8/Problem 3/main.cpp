#include <iostream>
using namespace std;

class Outscal {
public:
    int reverse(string a, string b) 
    {
        int dp[b.length() + 1];
        for (int i = 0; i <= a.length(); i++)
        {
            int temp[b.length() + 1];
            for (int j = 0; j <= b.length(); j++)
            {
                if(i == 0 || j == 0)
                {
                    temp[j] = i + j;
                }
                else if (a[i - 1] == b[j - 1])
                {
                    temp[j] = dp[j - 1];
                }
                else
                {
                    temp[j] = 1 + min(dp[j], temp[j - 1]);
                }
            }
            copy(temp, temp + b.length() + 1, dp);
        }
        return dp[b.length()];
    }
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED
//***********************************

int main() {
  string a, b;
  cin >> a >> b;
  class Outscal s;
  int ans = s.reverse(a, b);
  cout << ans;
}
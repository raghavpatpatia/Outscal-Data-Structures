#include <bits/stdc++.h>
using namespace std;

class Outscal {
public:
  int substring(string s) 
  {
    int n = s.length();
    vector<char> charIndex(256, -1);
    int start = 0, maxLength = 0;
    for (int i = 0; i < n; i++) 
    {
      if (charIndex[s[i]] >= start) 
      {
        start = charIndex[s[i]] + 1;
      }
      charIndex[s[i]] = i;
      int length = i - start + 1;
      if (length > maxLength) 
      {
        maxLength = length;
      }
    }
    return maxLength;
  }
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED
//***********************************

int main() {
  string a;
  cin >> a;
  class Outscal s;
  int ans = s.substring(a);
  cout << ans;
}
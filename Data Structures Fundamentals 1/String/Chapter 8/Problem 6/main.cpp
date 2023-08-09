#include <bits/stdc++.h>
using namespace std;

class Outscal {
public:     
    string substring(string s, string t)  {
        vector<int> frequency(256, 0);
        int requiredChars = t.length();
        int minLength = INT_MAX;
        int start = 0, windowStart = 0;

        for (int i = 0; i < requiredChars; i++)
        {
            frequency[t[i]]++;
        }

        for(int end = 0; end < s.length(); end++)
        {
            if (frequency[s[end]] > 0)
            {
                requiredChars--;
            }
            frequency[s[end]]--;
            while (requiredChars == 0)
            {
                if (end - windowStart + 1 < minLength)
                {
                    minLength = end - windowStart + 1;
                    start = windowStart;
                }

                frequency[s[windowStart]]++;
                if (frequency[s[windowStart]] > 0)
                {
                    requiredChars++;
                }
                windowStart++;
            }
        }
        if (minLength == INT_MAX)
        {
            return "";
        }
        return s.substr(start, minLength);
    }
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION 
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED 
//***********************************

int main() {
  string a,b;
  cin>>a>>b;
  class Outscal s;
  string ans = s.substring(a,b);
  cout<<ans;
}
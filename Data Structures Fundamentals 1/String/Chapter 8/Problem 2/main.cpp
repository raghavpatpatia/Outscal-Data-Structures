#include <iostream>
using namespace std;

class Outscal {
private:
    static const int MAX_CHAR = 26;
public:     
    int unique(string s)  
    {
      int frequency[MAX_CHAR] = {0};
      for (int i = 0; i < s.length(); i++)
      {
        frequency[s[i] - 'a']++;
      }
      for(int i = 0; i < s.length(); i++)
      {
        if (frequency[s[i] - 'a'] == 1)
        {
            return i;
        }
      }
      return -1;
    }
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION 
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED 
//***********************************

int main() {
  string a;
  cin>>a;
  class Outscal s;
  int ans = s.unique(a);
  cout<<ans;
}
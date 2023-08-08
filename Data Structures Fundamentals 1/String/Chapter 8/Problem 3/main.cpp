#include <iostream>
using namespace std;

class Outscal {
private:
    static const int MAX_CHAR = 26;
public:
    int reverse(string a, string b) 
    {
        int frequency[MAX_CHAR] = {0};
        int steps = 0;
        for (int i = 0; i < a.length(); i++)
        {
            frequency[a[i] - 'a']++;
        }
        for (int i = 0; i < b.length(); i++)
        {
            frequency[b[i] - 'a']--;
        }
        for (int i = 0; i < MAX_CHAR; i++)
        {
            steps += abs(frequency[i]);
        }
        return steps;
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
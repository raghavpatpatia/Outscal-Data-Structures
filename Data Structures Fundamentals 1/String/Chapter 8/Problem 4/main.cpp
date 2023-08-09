#include <iostream>
using namespace std;

class Outscal {
public:
    string longestPalindromeSubstring(string str) 
    {
        string longestPalindrome;  // To store the longest palindrome substring
        int n = str.length();  // Get the length of the input string
        int start = 0, length = 1, high, low;

        // Loop through each character of the input string
        for (int i = 0; i < n; i++) {
            low = i - 1;
            high = i;

            while (low >= 0 && high < n && str[low] == str[high]) {
                if (high - low + 1 > length) {
                    start = low;
                    length = high - low + 1;
                }
                high++;
                low--;
            }

            low = i - 1;
            high = i + 1;

            while (low >= 0 && high < n && str[low] == str[high]) {
                if (high - low + 1 > length) {
                    start = low;
                    length = high - low + 1;
                }
                high++;
                low--;
            }
        }

        // Print the longest palindrome substring from the input string
        int end = start + length;
        while (start < end)
        {
            longestPalindrome += str[start];
            start++;
        }

        return longestPalindrome;
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
  string ans = s.longestPalindromeSubstring(a);
  cout << ans;
}
#include <iostream>
using namespace std;

class Outscal {
private:
    bool isVowel(char ch)
    {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }

    void swap(char& leftCharacter, char& rightCharacter)
    {
        char temp = leftCharacter;
        leftCharacter = rightCharacter;
        rightCharacter = temp;
    }

public:     
    string reverse(string s)  
    {
        int left = 0;
        int right = s.length() - 1;
        while (left < right)
        {
            if (!isVowel(s[left]))
            {
                left++;
                continue;
            }
            if (!isVowel(s[right]))
            {
                right--;
                continue;
            }
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
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
  string ans = s.reverse(a);
  cout<<ans;
}
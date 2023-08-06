#include <iostream>

using namespace std;

string IsPalindrome(string str)
{
    for (int i = 0; i < str.length() / 2; i++)
    {
        if (str[i] != str[str.length() - i - 1])
        {
            return "No";
        }
    }
    return "Yes";
}

int main()
{
    string str;
    cout << "Enter your string: ";
    getline(cin, str);
    cout << "Is your string palindrome: " << IsPalindrome(str);
    return 0;
}
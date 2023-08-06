#include <iostream>

using namespace std;

const int MAX_CHAR = 256;

bool IsAnagram(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    int arr1[MAX_CHAR] = {0};
    int arr2[MAX_CHAR] = {0};

    for (int i = 0; i < str1.length(); i++)
    {
        arr1[str1[i]]++;
    }
    for (int i = 0; i < str2.length(); i++)
    {
        arr2[str2[i]]++;
    }

    for (int i = 0; i < MAX_CHAR; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str1, str2;
    cout << "Enter first string: ";
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);
    cout << "Is your string anagram: " << (IsAnagram(str1, str2) ? "true" : "false");
    return 0;
}
#include <iostream>

using namespace std;

const int MAX_CHAR = 256;

void CharacterCount(string str)
{
    int arr[MAX_CHAR] = {0};
    for (int i = 0; i < str.length(); i++)
    {
        arr[str[i]]++;
    }
    for (int i = 0; i < MAX_CHAR; i++)
    { 
        if (arr[i] > 0)
            cout << char(i) << " - " << arr[i] << endl;    
    }
}

int main()
{
    string str;
    cout << "Enter your string: ";
    getline(cin, str);
    cout << "Number of the unique characters present in the string:" << endl;
    CharacterCount(str);
    return 0;
}
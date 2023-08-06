#include <iostream>

using namespace std;

const int MAX_CHAR = 256;

void PrintDuplicate(string str)
{
    int arr[MAX_CHAR] = {0};

    for (int i = 0; i < str.length(); i++)
    {
        arr[str[i]]++;
    }

    for (int i = 0; i < MAX_CHAR; i++)
    {
        if (arr[i] > 1)
        {
            cout << char(i);
        }
    }
}

int main()
{
    string str;
    cout << "Enter your string: ";
    getline(cin, str);
    cout << "Duplicate characters in your string: ";
    PrintDuplicate(str);
    return 0;
}
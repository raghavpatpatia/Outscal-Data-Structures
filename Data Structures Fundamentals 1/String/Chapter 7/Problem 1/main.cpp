#include <iostream>

using namespace std;

const int MAX_CHAR = 26;

// Function to sort the characters in a string without using inbuilt functions
void SortString(string str)
{
    // Initializing an array to count occurrences of each character
    int arr[MAX_CHAR] = {0};
    // Counting the occurrences of each character in the string
    for (int i = 0; i < str.length(); i++)
    {
        // Incrementing the count for the corresponding character
        arr[str[i] - 'a']++;
    }

    // Printing the sorted characters based on the count array
    for (int i = 0; i < MAX_CHAR; i++)
    {
        for(int j = 0; j < arr[i]; j++)
        {
            // Printing the character i times counted in the array
            cout << (char)('a' + i);
        }
    }
}

int main()
{
    string str;
    cout << "Enter your string (only lowercase letters): ";
    cin >> str;
    cout << "Your sorted string: ";
    SortString(str);
    return 0;
}
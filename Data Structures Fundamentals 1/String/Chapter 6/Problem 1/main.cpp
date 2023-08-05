#include <iostream>
using namespace std;

void Reversed(string& str, int size)
{
    for(int i = size; i >= 0; i--)
    {
        cout << str[i];
    }
    cout << endl;
}

int main()
{
    string str;
    cout << "Enter your string: ";
    getline(cin, str);
    int size = str.length() - 1;
    cout << "Reversed string: ";
    Reversed(str, size);
    return 0;
} 
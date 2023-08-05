#include <iostream>

using namespace std;

void Invert(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if(islower(str[i]))
        {
            cout << (char)toupper(str[i]);
        }
        else if(isupper(str[i]))
        {
            cout << (char)tolower(str[i]);
        }
        else
        {
            cout << str[i];
        }
    }
}

int main()
{
    string str;
    cout << "Enter your string: ";
    cin >> str;
    cout << "Inverted text case of your string: ";
    Invert(str);
    return 0;
}
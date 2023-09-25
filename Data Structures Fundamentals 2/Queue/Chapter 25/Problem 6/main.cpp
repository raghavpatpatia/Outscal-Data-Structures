#include <bits/stdc++.h>
using namespace std;

bool isDistinctandLessthanFive(int num)
{
    string strNum = to_string(num);
    int digitCount[10] = {0};
    for (int i = 0; i < strNum.length(); i++)
    {
        char ch = strNum[i];
        int digit = ch - '0';
        if (digitCount[digit] > 0 || digit > 5)
        {
            return false;
        }
        digitCount[digit]++;
    }
    return true;
}

int findcount(string l, string r) 
{
    int count = 0;
    for (int i = stoi(l); i <= stoi(r); i++)
    {
        if (isDistinctandLessthanFive(i))
        {
            count++;
        }
    }
    return count;
}

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED
//***********************************

int main() {

  string l, r;
  cin >> l >> r;
  cout << findcount(l, r);

  return 0;
}

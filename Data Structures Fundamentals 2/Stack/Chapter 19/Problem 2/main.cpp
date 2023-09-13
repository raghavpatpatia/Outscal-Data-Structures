#include <bits/stdc++.h>
using namespace std;

class Outscal {
public:
  vector<int> temperatures(vector<int> temperatures) {
    // Write your code here
    int n = temperatures.size();
    vector<int> warmerDays(n, 0);
    stack<int> daysStack;
    for (int i = 0; i < n; i++)
    {
        while (!daysStack.empty() && temperatures[i] > temperatures[daysStack.top()])
        {
            int previousDay = daysStack.top();
            daysStack.pop();
            warmerDays[previousDay] = i - previousDay;
        }
        daysStack.push(i);
    }
    return warmerDays;
  }
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION
// ELSE YOU SUBMISSION WILL BE DISQUALIFIE

int main() {
  int m, i;
  int temp;
  vector<int> brr;
  cin >> m;
  while (m) {
    cin >> temp;
    brr.push_back(temp);
    m--;
  }
  class Outscal s;
  vector<int> ans = s.temperatures(brr);
  for (i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  return (0);
}

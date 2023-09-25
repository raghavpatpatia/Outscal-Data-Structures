#include <bits/stdc++.h>
using namespace std;

int downToZero(int n) 
{
    vector<int> dp(n + 1, 0);
    queue<int> q;
    q.push(n);
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (curr == 0)
        {
            return dp[0];
        }
        for (int i = 2; i * i <= curr; i++)
        {
            if (curr % i == 0)
            {
                int next = max(i, curr / i);
                if (dp[next] == 0)
                {
                    dp[next] = dp[curr] + 1;
                    q.push(next);
                }
            }
        }
        if (dp[curr - 1] == 0)
        {
            dp[curr - 1] = dp[curr] + 1;
            q.push(curr - 1);
        }
    }
    return dp[0];
}

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION 
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED 
//***********************************

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        int result = downToZero(n);
        cout << result << "\n";
    }
    return 0;
}

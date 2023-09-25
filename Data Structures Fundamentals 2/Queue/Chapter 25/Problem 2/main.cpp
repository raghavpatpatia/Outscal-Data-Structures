#include <bits/stdc++.h>
using namespace std;

template <typename T>
void KiraOperations(int n)
{
    queue<T> q;
    while (n--)
    {
        char operations;
        cin >> operations;
        if (operations == 'E' || operations == 'e')
        {
            T value;
            cin >> value;
            q.push(value);
            cout << q.size() << endl;
        }
        else if (operations == 'D' || operations == 'd')
        {
            if (q.empty())
            {
                cout << -1 << " " << 0 << endl;
            }
            else
            {
                cout << q.front() << " " << q.size() - 1 << endl;
                q.pop();
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    KiraOperations<int>(n);
    return 0;
}
#include <bits/stdc++.h> 
using namespace std; 

int remainingCard(int n) 
{ 
    queue<int> cards;
    for(int i = 1; i <= n; i++)
    {
        cards.push(i);
    }

    while(cards.size() != 1)
    {
        cards.push(cards.front());
        cards.pop();
        cards.pop();
    }

    return cards.front();
} 

// Driver code 
int main() 
{ 
	int n; 
    cin >> n;
	cout << remainingCard(n); 
  
	return 0; 
} 

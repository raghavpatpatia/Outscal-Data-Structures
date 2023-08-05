#include <iostream>

using namespace std;

class Player
{
private:
    string name;
public:
    Player(string name) : name(name) {}
    string operator + (const Player& player2)
    {
        return name + player2.name;
    }
};

int main()
{
    string player1Name, player2Name;
    cout << "Enter Player 1 name: ";
    cin >> player1Name;
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    Player player1(player1Name);
    Player player2(player2Name);
    cout << player1 + player2;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    vector<int> levels;
    for (int i = 0; i < 10; i++)
    {
        levels.push_back(i + 1);
    }

    cout << "Enemies on each level:\n";
    for (int i = 0; i < levels.size(); i++)
    {
        cout << "Enemies on level " << i << ": " << levels.at(i) << endl;
    }

    int sum = accumulate(levels.begin(), levels.end(), 0);

    cout << endl << "Total number of enemies in the game: " << sum << endl;

    cout << endl << "Total number of levels are: " << levels.size() << endl;

    levels.resize(5);    
    cout << endl << "Changing size of levels: " << levels.size() << endl;
    for (int i = 0; i < levels.size(); i++)
    {
        cout << "Enemies on level " << i << ": " << levels.at(i) << endl;
    }

    reverse(levels.begin(), levels.end());
    cout << endl << "Reversing enemies order: " << endl;
    for (int i = 0; i < levels.size(); i++)
    {
        cout << "Enemies on level " << i << ": " << levels.at(i) << endl;
    }
    cout << endl << "Adding duplicate enemies on level 5 and 6..." << endl;
    levels.push_back(1);
    levels.push_back(1);
    for (int i = 0; i < levels.size(); i++)
    {
        cout << "Enemies on level " << i << ": " << levels.at(i) << endl;
    }

    cout << endl << "Removing duplicate enemies on level 5 and 6..." << endl;
    levels.erase(unique(levels.begin(), levels.end()), levels.end());
    for (int i = 0; i < levels.size(); i++)
    {
        cout << "Enemies on level " << i << ": " << levels.at(i) << endl;
    }

    return 0;
}
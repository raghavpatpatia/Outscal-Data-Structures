#include <iostream>

using namespace std;

void MinMax(int arr[], int size)
{
    int highScore = arr[0];
    int highScoreTeam = 0;
    int lowScore = arr[0];
    int lowScoreTeam = 0;
    for (int i = 1; i < size; i++)
    {
        if (highScore < arr[i])
        {
            highScore = arr[i];
            highScoreTeam = i;
        }
        if (lowScore > arr[i])
        {
            lowScore = arr[i];
            lowScoreTeam = i;
        }
    }
    cout << endl << "Highest score is: " << highScore << endl << "By team: " << highScoreTeam << endl;
    cout << endl << "Lowest score is: " << lowScore << endl << "By team: " << lowScoreTeam << endl;
}

void ScoreInput()
{
    int teams;
    cout << "Enter number of teams: ";
    cin >> teams;
    int scoreArray[teams];
    int score;
    cout << "Enter score for the teams:" << endl;
    for (int i = 0; i < teams; i++)
    {
        cout << "Enter score for team " << i << ": ";
        cin >> score;
        scoreArray[i] = score;
    }
    MinMax(scoreArray, teams);
}

int main()
{
    ScoreInput();
    return 0;
}
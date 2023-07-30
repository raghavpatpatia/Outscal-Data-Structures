#include <iostream>

using namespace std;

bool WordSearch(char** arr, string word, int x, int y, int rows, int columns, int level)
{
    int length = word.length();

    // Word match
    if (level == length)
        return true;
    
    // Out of the bounds
    if (x < 0 || y < 0 || x >= rows || y >= columns)
        return false;
    
    // If array matches the letter while recursion
    if (arr[x][y] == word[level])
    {
        // Making this cell as visited
        char temp = arr[x][y];
        arr[x][y] = '-';

        // Finding pattern in 4 directions
        bool search = WordSearch(arr, word, x - 1, y, rows, columns, level + 1) ||
                      WordSearch(arr, word, x + 1, y, rows, columns, level + 1) ||
                      WordSearch(arr, word, x, y - 1, rows, columns, level + 1) ||
                      WordSearch(arr, word, x, y + 1, rows, columns, level + 1);
        
        // Making this cell as unvisited again
        arr[x][y] = temp;
        return search;
    }

    else // If pattern is not matching then returning false
        return false;
}

bool WordMatch(char** arr, string word, int rows, int columns)
{
    int length = word.length();
    // If characters in array are less than word's length
    if (length > rows * columns) return false;

    // Traverse in the array and if first letter matches search for the word through recursion. 
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if (arr[i][j] == word[0])
            {
                if (WordSearch(arr, word, i, j, rows, columns, 0))
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cout << "Enter number of rows for the grid: ";
    cin >> n;
    cout << "Enter number of columns for the grid: ";
    cin >> m;
    // dynamically creating array
    char** arr = new char*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new char[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "Enter character ( " << i << " ) ( " << j << " ): ";
            cin >> arr[i][j];
        }
    }

    string word;
    cout << endl << "Enter word You want to search: ";
    cin >> word;

    cout << endl << "Your grid:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "Your Word: " << word << endl;
    // If WordMatch function returns true that means word is found and print true otherwise print false
    cout << "Word found: " << (WordMatch(arr, word, n, m) ? "True" : "False") << endl;
    // Free up dynamically created array
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
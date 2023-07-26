#include <iostream>

using namespace std;
int main()
{
    int arr[10][10];
    for (int rows = 0; rows < 10; rows++)
    {
        for (int columns = 0; columns < 10; columns++)
        {
            if ((rows + columns) % 2 == 0)
            {
                arr[rows][columns] = 2 * (rows + columns);
            }
            else
            {
                arr[rows][columns] = 3 * (rows + columns);
            }
            cout << arr[rows][columns] << " ";
        }
        cout << endl;
    }
    return 0;
}
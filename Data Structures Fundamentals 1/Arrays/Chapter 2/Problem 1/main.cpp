#include <iostream>

using namespace std;
int main()
{
    int arr[15];
    for (int i = 0; i < 15; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] = 2 * i;
        }
        else
        {
            arr[i] = 3 * i;
        }
        cout << arr[i] << " ";
    }
    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

void PrintSubsets(int arr[], int size)
{
    unsigned int powerSize = pow(2, size);

    for (int i = 0; i < powerSize; i++)
    {
        cout << "[";
        for (int j = 0; j < size; j++)
        {
            if (i & (1 << j))
            {
                cout << arr[j];
            }
        }
        cout << "]" << endl;
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter elements in the array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i << " element of the array: ";
        cin >> arr[i];
    }
    cout << endl << "Your array: {";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "}" << endl;
    cout << "Subset of array: " << endl << "{" << endl;
    PrintSubsets(arr, size);
    cout << "}";
    return 0;
}
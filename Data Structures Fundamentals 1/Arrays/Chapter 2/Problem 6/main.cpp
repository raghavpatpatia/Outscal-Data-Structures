#include <iostream>

using namespace std;

void RearrangeArray()
{
    int size;
    cout << "Enter size of the array: ";
    cin >> size;
    int arr[size];
    int arr2[size];
    cout << endl << "Enter elements of array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i << ": ";
        cin >> arr[i]; 
    }

    cout << endl << "Your array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= 0)
        {
            arr2[j] = arr[i];
            j++;
        }
    }
    
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            arr2[j] = arr[i];
            j++;
        }
    }

    cout << endl << "Rearranged array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr2[i] << " ";
    }
}

int main()
{
    RearrangeArray();
    return 0;
}


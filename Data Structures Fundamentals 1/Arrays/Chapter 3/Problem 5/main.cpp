#include <iostream>

using namespace std;

int SmallestPositiveNumber(int arr[], int size)
{
    int ptr = 0;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == 1)
        {
            ptr = 1;
            break;
        }
    }

    if (ptr == 0)
        return 1;

    for(int i = 0; i < size; i++)
    {
        if (arr[i] <= 0 || arr[i] > size)
        {
            arr[i] = 1;
        }
    }

    for (int i = 0; i < size; i++)
        arr[(arr[i] - 1) % size] += size;
    
    for (int i = 0; i < size; i++)
    {
        if (arr[i] <= size)
            return (i + 1);
    }

    return size + 1;
}

int main()
{
    int size;
    cout << "Enter size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter elements in the array: " << endl; 
    for(int i = 0; i < size; i++)
    {
        cout << "Enter " << i << " element of the array: ";
        cin >> arr[i];
    }
    cout << "Your array: { ";
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << '}' << endl;
    cout << "Smallest missing positive number is: " << SmallestPositiveNumber(arr, size);
    return 0;
}
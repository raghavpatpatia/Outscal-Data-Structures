#include <iostream>

using namespace std;

int MissingElement(int arr[], int size)
{
    int a = arr[0];
    int b = 1;
    for (int i = 1; i < size - 1; i++)
    {
        a = a ^ arr[i];
    }
    for (int i = 2; i <= size; i++)
    {
        b = b ^ i;
    }
    return (a ^ b);
}

int main()
{
    int size;
    cout << "Enter size of the array: ";
    cin >> size;
    int arr[size - 1];
    cout << "Enter elements in the array: " << endl; 
    for(int i = 0; i < size - 1; i++)
    {
        cout << "Enter " << i << " element of the array: ";
        cin >> arr[i];
    }
    cout << "Your array: { ";
    for(int i = 0; i < size - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << '}' << endl;
    cout << "Missing element: " << MissingElement(arr, size);
    return 0;
}
#include <iostream>

using namespace std;

void RepeatingElements(int arr[], int size)
{
    int frequency[size] = {0};
    for (int i = 0; i < size; i++)
    {
        frequency[arr[i]]++;
    }

    bool foundRepeat = false;

    for (int i = 0; i < size; i++)
    {
        if (frequency[i] > 1)
        {
            foundRepeat = true;
            cout << i << " ";
        }
    }

    if (!foundRepeat) cout << "-1";

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
    cout << "Repeating element: ";
    RepeatingElements(arr, size);
    return 0;
}
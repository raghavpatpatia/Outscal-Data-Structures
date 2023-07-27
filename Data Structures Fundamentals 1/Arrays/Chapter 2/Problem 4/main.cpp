#include <iostream>

using namespace std;

void FindPeekElements(int arr[], int size, int peekIndices[], int& peekCount) {
    peekCount = 0;
    for (int i = 0; i < size; i++) 
    {
        if ((i == 0 || arr[i] >= arr[i - 1]) && (i == size - 1 || arr[i] >= arr[i + 1])) 
        {
            peekIndices[peekCount] = i;
            peekCount++;
        }
    }
}

void PeekElementsOfArray() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter elements of the array: " << endl;
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
    cout << endl;

    int peekIndices[size];
    int peekCount;
    FindPeekElements(arr, size, peekIndices, peekCount);

    if (peekCount == 0) 
    {
        cout << "No peak element found in the array." << endl;
    } 
    else 
    {
        cout << "Indices of peak elements: ";
        for (int i = 0; i < peekCount; i++) 
        {
            cout << peekIndices[i] << " ";
        }
    }
}

int main() 
{
    PeekElementsOfArray();
    return 0;
}

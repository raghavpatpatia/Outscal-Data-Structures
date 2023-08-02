#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    vector<int> vect;
    for (int i = 0; i < 10; i++)
    {
        vect.push_back(i + 1);
    }
    vector<int>::iterator it;
    cout << endl << "Elements inside the vector are: { ";
    for (it = vect.begin(); it < vect.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "}" << endl;
    return 0;
}
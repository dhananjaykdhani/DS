#include <iostream>
using namespace std;

int main()
{
    int a[10], size;
    cout << "Enter size of array: ";
    cin >> size;

    cout << "Enter element of array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }

    cout << "Element of array";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
}
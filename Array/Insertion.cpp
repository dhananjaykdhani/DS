#include <iostream>
using namespace std;

int main()
{
    int a[550], size, num, pos;
    cout << "Enter size of array: ";
    cin >> size;

    cout << "Enter element of array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }

    cout << "Enter data that you want to insert into array: ";
    cin >> num;

    cout << "Position of Array: ";
    cin >> pos;
    if (pos <= 0 || pos > size + 1)
    {
        cout << "invalid Positon";
    }
    else
    {
        for (int i = size - 1; i >= pos - 1; i--)
        {
            a[i + 1] = a[i];
        }
        a[pos - 1] = num;
        size++;
    }

    for (int i = 0; i < size; i++)
    {
        cout << a[i]<<" ";
    }

    return 0;
}
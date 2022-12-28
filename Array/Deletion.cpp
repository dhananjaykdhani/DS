#include <iostream>
using namespace std;

int main()
{
    int arr[15];
    int pos, i, num;
    cout << "Enter the number of elements in an array: \n ";
    cin >> num;

    cout << "Enter " << num << " elements in array: ";

    for (i = 0; i < num; i++)
    {
        cin >> arr[i];
    }

    cout << "Position of the array element which you want to delete: \n ";
    cin >> pos;

    if (pos >= num + 1)
    {
        cout << " \n Deletion is not possible in the array.";
    }
    else
    {
        for (i = pos - 1; i < num - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        cout << "The resultant array is: \n";

        for (i = 0; i < num - 1; i++)
        {
            cout << " arr[" << i << "] = ";
            cout << arr[i];
        }
    }
    return 0;
}
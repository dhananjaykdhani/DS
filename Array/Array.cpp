#include <iostream>
using namespace std;

int a[50], size, num, pos, search;

void insert()
{
    cout << "Enter data that you want to insert into array: ";
    cin >> num;

    cout << "Position of Array: ";
    cin >> pos;
    if (pos <= 0 || pos > size + 1)
    {
        cout << "invalid Positon\n";
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

    cout << "The resultant array is: \n";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
}

void del()
{
    int i;

    cout << "Position of the array element which you want to delete: \n ";
    cin >> pos;

    if (pos >= size + 1)
    {
        cout << " \n Deletion is not possible in the array.";
    }
    else
    {
        for (i = pos - 1; i < size - 1; i++)
        {
            a[i] = a[i + 1];
        }

        cout << "The resultant array is: \n";

        for (i = 0; i < size - 1; i++)
        {
            cout << a[i] << " ";
        }
    }
}

void sea()
{
    int i;

    cout << "Enter element which you want to search: ";
    cin >> search;

    for (i = 0; i < size; i++)
    {
        if (a[i] == search)
        {
            cout << "Element found";
            break;
        }
    }
    if (a[i] != search)
    {
        cout << "Element not Found";
    }
}

int main()
{
    cout << "Enter size of array: ";
    cin >> size;

    cout << "Enter element of array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }

    int x = 0;
    while (true)
    {
        cout << "\nChoose Your Operation:\n\t1. Insert \n\t2. Delete\n\t3. Search\n\t\t: ";
        cin >> x;
        if (x == 1)
            insert();
        else if (x == 2)
            del();
        else if (x == 3)
            sea();
        else
            cout << "Invalide Choose again...\n\n";
    }

    return 0;
}
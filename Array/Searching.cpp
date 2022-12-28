#include <iostream>
using namespace std;

int main()
{
    int a[8], search,i;

    cout << "Enter elements: ";
    for (int i = 0; i < 8; i++)
    {
        cin >> a[i];
    }
    
    cout << "Enter element which you want to search: ";
    cin >> search;

    for (i = 0; i < 8; i++)
    {
        if (a[i] == search)
        {
            cout<<"Element found";
            break;
        }
    }
    if(a[i]!=search)
    {
        cout << "Element not Found";
    }
}
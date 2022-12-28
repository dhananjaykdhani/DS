#include <iostream>
using namespace std;
int main()
{
    int i, j, a, n;
    cout << "Enter the Number of Elements: \n";
    cin >> n;
    
    int number[n];

    cout << "Enter the Elements: \n";
    for (i = 0; i < n; ++i)
    {
        cin >> number[i];
    }

    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {

            if (number[i] > number[j])
            {
                a = number[i];
                number[i] = number[j];
                number[j] = a;
            }
        }
    }

    cout << "The numbers arranged in ascending order are given below \n";
    for (i = 0; i < n; ++i)
        cout << number[i] << " ";
}
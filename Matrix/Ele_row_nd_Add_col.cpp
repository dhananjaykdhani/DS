

#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter the number of Row of Matrix: ";
    cin >> n;

    int mat_1[n][n];

    cout << "Enter the element of Matrix Row wise:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> mat_1[i][j];
        }

    cout << "Given Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "[";
        for (int j = 0; j < n; j++)
        {
            cout << " " << mat_1[i][j];
            if (j == n - 1)
            {
                cout << " ]" << endl;
            }
        }
    }

    cout << "Address of matrix usin column major:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << " " << &mat_1[j][i] << endl;
        }
    }
}
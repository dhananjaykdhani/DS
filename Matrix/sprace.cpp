#include <iostream>
using namespace std;

int main()
{
    int max = 30;
    int s1[max][3], s2[max][3], m = 0, n = 0, l = 0;
    cout << "Enter the matrix size & no of elements: ";
    cin >> m >> n >> l;

    if (l > (m * n / 2))
        return 0;

    s1[0][0] = m;
    s1[0][1] = n;
    s1[0][2] = l;
    for (int i = 1; i < l; i++)
    {
        cout << "Enter the row & column & value: ";
        cin >> s1[i][0] >> s1[i][1] >> s1[i][2];
    }

    s2[0][0] = s1[0][1];
    s2[0][1] = s1[0][0];
    s2[0][2] = s1[0][2];
    for (int i = 1; i <= l; i++)
    {
        s2[i][0] = s1[i][1];
        s2[i][1] = s1[i][0];
        s2[i][2] = s1[i][2];
    }

    cout << "The matrix is: " << endl;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << s1[i][j] << " ";
        }
        cout << endl;
    }
    cout << "The transpose matrix is: " << endl;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << s2[i][j] << " ";
        }
        cout << endl;
    }
}
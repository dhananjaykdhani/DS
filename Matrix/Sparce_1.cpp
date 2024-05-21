#include <iostream>
using namespace std;
#define max 30

int s1[max][3], s2[max][3], s[max][3], sr[max][3], row, col, len;

void set()
{
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            s1[i][j] = 0;
            s2[i][j] = 0;
            s[i][j] = 0;
        }
    }
}

void input()
{
    cout << "Enter the Number of row & column & length of matrix: ";
    cin >> row >> col >> len;

    if (len > (row * col) / 2)
    {
        cout << "Given Matrix is not sparce.\nPlease ";
        input();
        return;
    }

    s[0][0] = row;
    s[0][1] = col;
    s[0][2] = len;

    cout << "Enter the element of matrix 1:\n";
    for (int i = 1; i <= len; i++)
    {
        cin >> s1[i][1] >> s1[i][2] >> s1[i][2];
    }
    cout << "given matrix 1:\n";
    for (int i = 0; i <= len; i++)
    {
        cout << s1[i][0] << " " << s1[i][1] << " " << s1[i][2] << " \n";
    }

    cout << "Enter the element of matrix 1:\n";
    for (int i = 1; i <= len; i++)
    {
        cin >> s2[i][1] >> s2[i][2] >> s2[i][2];
    }
    cout << "given matrix 2:\n";
    for (int i = 0; i <= len; i++)
    {
        cout << s2[i][0] << " " << s2[i][1] << " " << s2[i][2] << " \n";
    }
}

void add()
{
    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            s[i][j] = s1[i][j] + s2[i][j];
        }
    }

    int k =1;
    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (s[i][j] != 0)
            {
                sr[k][0] = i;
                sr[k][1] = j;
                sr[k][2] = s[i][j];
                k++;
            }
        }
    }

    cout << "Added matrix \n";
    for (int i = 1; i <= k; i++)
    {
        cout << sr[i][0] << " " << sr[i][1] << " " << sr[i][2] << " \n";
    }
}

int main()
{
    set();
    input();
    add();
}
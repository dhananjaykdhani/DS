// Sparce Matric Addition and Multiplication

#include <iostream>
using namespace std;

#define max 30
int s1[max][3], s2[max][3], s3[max][3], m = 0, n = 0, l = 0;

void input(int s[max][3], int &m, int &n, int &l)
{
    cout << "Enter the matrix size & no of elements: ";
    cin >> m >> n >> l;
    if (l > (m * n / 2))
        return;
    s[0][0] = m;
    s[0][1] = n;
    s[0][2] = l;
    for (int i = 1; i <= l; i++)
    {
        cout << "Enter the row & column & value: ";
        cin >> s[i][0] >> s[i][1] >> s[i][2];
    }
}

void display(int s[max][3], int l)
{
    cout << "The matrix is: " << endl;
    for (int i = 0; i <= l; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
}

void add(int s1[max][3], int s2[max][3], int s3[max][3], int l1, int l2)
{
    int i = 1, j = 1, k = 1;
    while (i <= l1 && j <= l2)
    {
        if (s1[i][0] == s2[j][0] && s1[i][1] == s2[j][1])
        {
            s3[k][0] = s1[i][0];
            s3[k][1] = s1[i][1];
            s3[k][2] = s1[i][2] + s2[j][2];
            i++;
            j++;
            k++;
        }
        else if (s1[i][0] < s2[j][0] || (s1[i][0] == s2[j][0] && s1[i][1] < s2[j][1]))
        {
            s3[k][0] = s1[i][0];
            s3[k][1] = s1[i][1];
            s3[k][2] = s1[i][2];
            i++;
            k++;
        }
        else
        {
            s3[k][0] = s2[j][0];
            s3[k][1] = s2[j][1];
            s3[k][2] = s2[j][2];
            j++;
            k++;
        }
    }
    while (i <= l1)
    {
        s3[k][0] = s1[i][0];
        s3[k][1] = s1[i][1];
        s3[k][2] = s1[i][2];
        i++;
        k++;
    }
    while (j <= l2)
    {
        s3[k][0] = s2[j][0];
        s3[k][1] = s2[j][1];
        s3[k][2] = s2[j][2];
        j++;
        k++;
    }
    s3[0][2] = k - 1;
}

void multiply(int s1[max][3], int s2[max][3], int s3[max][3], int l1, int l2)
{
    int i = 1, j = 1, k = 1;
    while (i <= l1)
    {
        j = 1;
        while (j <= l2)
        {
            if (s1[i][1] == s2[j][0])
            {
                s3[k][0] = s1[i][0];
                s3[k][1] = s2[j][1];
                s3[k][2] = s1[i][2] * s2[j][2];
                k++;
            }
            j++;
        }
        i++;
    }
    s3[0][2] = k - 1;
}

int main()
{
    input(s1, m, n, l);
    display(s1, l);
    input(s2, m, n, l);
    display(s2, l);
    add(s1, s2, s3, s1[0][2], s2[0][2]);
    display(s3, s3[0][2]);
    multiply(s1, s2, s3, s1[0][2], s2[0][2]);
    display(s3, s3[0][2]);
    return 0;
}
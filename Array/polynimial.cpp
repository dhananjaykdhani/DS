#include <iostream>

using namespace std;
int deg1, deg2, dsum, ch;
int p1[10], p2[10], p3[10], p4[20];
void in()
{
    cout << "Enter degrees for polynomial equation 1 & 2" << endl;
    cin >> deg1 >> deg2;
    cout << "First polynomial equation " << endl;
    for (int i = 0; i < deg1 + 1; i++)
    {
        cout << "Coefficient of " << i + 1 << " term -->";
        cin >> p1[i];
    }
    for (int i = 0; i <= deg1; i++)
    {
        if (i < deg1)
            cout << p1[i] << " x^" << i << " + ";
        else
            cout << p1[i] << " x^" << i << endl;
    }
    cout << "Second polynomial equation " << endl;
    for (int j = 0; j < deg2 + 1; j++)
    {
        cout << "Coefficient of " << j + 1 << " term -->";
        cin >> p2[j];
    }
    for (int i = 0; i <= deg2; i++)
    {
        if (i < deg2)
            cout << p2[i] << " x^" << i << " + ";
        else
            cout << p2[i] << " x^" << i << endl;
    } 
}
void add()
{
    if (deg1 > deg2)
        dsum = deg1;
    else
        dsum = deg2;
    for (int i = 0; i < dsum + 1; i++)
    {
        p3[i] = 0;
    }
    for (int i = 0; i < deg1 + 1; i++)
    {
        p3[i] += p1[i];
    }
    for (int i = 0; i < deg2 + 1; i++)
    {
        p3[i] += p2[i];
    }
    cout << "Addition of polynomials is " << endl;
    for (int i = 0; i <= dsum; i++)
    {
        if (i < dsum)
            cout << p3[i] << " x^" << i << " + ";
        else
            cout << p3[i] << " x^" << i << endl;
    }
}
void mult()
{
    cout << "Multiplication of matrix is " << endl;
    for (int i = 0; i <= deg1 + deg2; i++)
    {
        p4[i] = 0;
    }
    for (int i = 0; i <= deg1; i++)
    {
        for (int j = 0; j <= deg2; j++)
        {
            p4[i + j] += p1[i] * p2[j];
        }
    }
    for (int i = 0; i <= deg1 + deg2; i++)
    {
        if (i < deg1 + deg2)
            cout << p4[i] << " x^" << i << " + ";
        else
            cout << p4[i] << " x^" << i << endl;
    }
}
void choice()
{
    cout << "Enter choice" << endl;
    cout << "1)For Addition" << endl;
    cout << "2)For Multiplication" << endl;
    cout << "3)for exit" << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        add();
        break;
    }
    case 2:
    {
        mult();
        break;
    }
    case 3:
        break;
    default:
        cout << "No valid operation " << endl;
    }
}
int main()
{
    in();
    choice();
}
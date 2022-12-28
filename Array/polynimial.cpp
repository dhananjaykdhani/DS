#include <iostream>
using namespace std;

int main()
{
    int deg1, deg2, deg;

    cout << "Enter the highest degree of 1st and 2nd Polynomial: ";
    cin >> deg1 >> deg2;

    if (deg1 > deg2)
        deg = deg1;
    else
        deg = deg2;

    int pol1[deg1 + 1], pol2[deg2 + 1], pol[deg1 + deg2 + 1];

    cout << "Enter the coficient of Polynomial 1:\n";
    for (int i = 0; i <= deg1; i++)
        cin >> pol1[i];

    cout << "Enter the coficient of Polynomial 2:\n";
    for (int i = 0; i <= deg2; i++)
        cin >> pol2[i];

    // Add
    for (int i = 0; i < deg1 + deg2 + 1; i++)
        pol[i] = 0;

    for (int i = 0; i < deg1 + 1; i++)
        pol[i] += pol1;

    for (int i = 0; i < deg2 + 1; i++)
        pol[i] += pol2;

    // multiply
    for (int i = 0;)
}
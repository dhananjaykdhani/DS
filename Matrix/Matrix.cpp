// Preform Addition, Subtraction, Multiplication and Transpose Opration Between two Matrix.

#include <iostream>
using namespace std;

int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
int mat_1[10][10], mat_2[10][10], mat_reslut[10][10];

// Functions
void input();
void getdata();
void showdata();
void mat_reset();
void pros();
void condi();

void add();
void sub();
void multi();
void trans();
void result();
// input row & column of both matrix
void input()
{
    cout << "Enter the Row and Column For Matrix 1: ";
    cin >> r1 >> c1;

    cout << "Enter the Row and Column For Matrix 2: ";
    cin >> r2 >> c2;
}

// input elements of matrix
void getdata()
{
    cout << "Enter the elements of matrix 1 row wise: \n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
        {
            cin >> mat_1[i][j];
        }

    cout << "Enter the elements of matrix 2 row wise: \n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
        {
            cin >> mat_2[i][j];
        }
}

// show the entered element of matrix
void showdata()
{
    cout << "Elements of matrix 1: \n";
    for (int i = 0; i < r1; i++)
    {
        cout << "[ ";
        for (int j = 0; j < c1; j++)
        {
            cout << mat_1[i][j] << " ";
        }
        cout << "]" << endl;
    }
    cout << "Elements of matrix 2: \n";
    for (int i = 0; i < r2; i++)
    {
        cout << "[ ";
        for (int j = 0; j < c2; j++)
        {
            cout << mat_2[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

// to create or re-set the resuls array of matrix
void mat_reset()
{
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
        {
            mat_reslut[i][j] = 0;
        }
}

void result()
{
    for (int i = 0; i < r2; i++)
    {
        cout << "[ ";
        for (int j = 0; j < c2; j++)
        {
            cout << mat_reslut[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

// addition
void add()
{
    mat_reset();
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
        {
            mat_reslut[i][j] += mat_1[i][j] + mat_2[i][j];
        }

    result();
}

// subtraction
void sub()
{
    mat_reset();
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
        {
            mat_reslut[i][j] += mat_1[i][j] - mat_2[i][j];
        }

    result();
}

// multiplication
void multi()
{
    mat_reset();
    if (r1 > r2)
    {
        for (int i = 0; i < r1; i++)
            for (int j = 0; j < c2; j++)
                for (int k = 0; k < c2; k++)
                {
                    mat_reslut[i][j] += mat_1[i][k] * mat_2[k][j];
                }
    }
    else
    {
        for (int i = 0; i < r2; i++)
            for (int j = 0; j < c1; j++)
                for (int k = 0; k < c1; k++)
                {
                    mat_reslut[i][j] += mat_2[i][k] * mat_1[k][j];
                }
    }

    result();
}

// transpose
void trans()
{
    mat_reset();
    cout << "Transpose of matrix 1: \n";
    for (int i = 0; i < c1; i++)
    {
        cout << "[ ";
        for (int j = 0; j < r1; j++)
        {
            cout << mat_1[j][i] << " ";
        }
        cout << "]" << endl;
    }
    cout << "Transpose of matrix 2: \n";
    for (int i = 0; i < c2; i++)
    {
        cout << "[ ";
        for (int j = 0; j < r2; j++)
        {
            cout << mat_2[j][i] << " ";
        }
        cout << "]" << endl;
    }
}
void condi()
{
    if (r1 == r2 && r2 == c1 && c1 == c2 && c2 == r1)
    {
        int x;
        cout << "Choose Your Opration: \n0. Re-enter Row & Column.\n1. Addition \n2. Subtraction \n3. Multiplication\n4. Transpose \n5. All of them\n\n\t:  ";
        cin >> x;

        if (x == 1)
        {
            getdata();
            showdata();
            cout << "Addition:\n";
            add();
        }
        else if (x == 0)
        {
            cout << "Re-enter Rows & Column\n";
            pros();
        }
        else if (x == 2)
        {
            getdata();
            showdata();
            cout << "Subtranction:\n";
            sub();
        }
        else if (x == 3)
        {

            getdata();
            showdata();
            cout << "Multiplication:\n";
            multi();
        }
        else if (x == 4)
        {
            getdata();
            showdata();
            cout << "Transpose:\n";
            trans();
        }
        else if (x == 5)
        {
            getdata();
            showdata();
            cout << "Addition:\n";
            add();
            cout << "Subtranction:\n";
            sub();
            cout << "Multiplication:\n";
            multi();
            cout << "Transpose:\n";
            trans();
        }
        else
        {
            cout << "Entered wrong value please ";
            condi();
        }
    }
    else if (r1 == c2 && r2 == c1)
    {
        int x;
        cout << "Choose Your Opration: \n0. Re-enter Row & Column.\n1. Multiplication\n\n\t:  ";
        cin >> x;

        if (x == 1)
        {
            getdata();
            showdata();
            cout << "Multiplication:\n";
            multi();
        }
        else if (x == 0)
        {
            cout << "Re-enter Rows & Column\n";
            pros();
        }
        else
        {
            cout << "Entered wrong value please ";
            condi();
        }
    }
    else if (r1 == r2 && c1 == c2)
    {
        int x;
        cout << "Choose Your Opration: \n0. Re-enter Row & Column.\n1. Addition \n2. Subtraction \n3. All of them\n\n\t:  ";
        cin >> x;
        if (x == 1)
        {
            getdata();
            showdata();
            cout << "Addition:\n";
            add();
        }
        else if (x == 0)
        {

            cout << "Re-enter Rows & Column\n";
            pros();
        }
        else if (x == 2)
        {
            getdata();
            showdata();
            cout << "Subtranction:\n";
            sub();
        }
        else if (x == 3)
        {
            getdata();
            showdata();
            cout << "Addition:\n";
            add();
            cout << "Subtranction:\n";
            sub();
        }
        else
        {
            cout << "Entered wrong value please ";
            condi();
        }
    }
    else
    {
        cout << "Re-enter Rows & Column\n";
        pros();
    }
}

// main function
int main()
{
    int x = 1;
    int y;
    while (y != 0)
    {
        cout << "Operation no: " << x << "." << endl;
        pros();
        cout << "Do You want to Perform Next Operation: \n\t0. No\n\tEnter any other key to continew...\n\t\t:";
        cin >> y;
        x++;
    }
    cout << "Exited from Program...";
}

void pros()
{
    input();
    mat_reset();
    condi();
}
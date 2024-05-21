// Program to Check expression is correctly parenthesized
#include <iostream>
using namespace std;

char stack[50];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}
char pop()
{
    return stack[top--];
}
bool isBalanced(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '(')
            push(str[i]);
        else if (str[i] == ')')
        {
            if (top == -1)
                return false;
            pop();
        }
        i++;
    }
    if (top == -1)
        return true;
    else
        return false;
}
int main()
{
    char str[50];
    cout << "Enter Expression: ";
    cin >> str;
    if (isBalanced(str))
        cout << "Yes";
    else
        cout << "No";
}
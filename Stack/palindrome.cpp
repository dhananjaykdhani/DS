#include <iostream>
using namespace std;
char stack[100];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}
char pop()
{
    return stack[top--];
}
bool isPalindrome(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        push(str[i]);
        i++;
    }
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != pop())
            return false;
        i++;
    }
    return true;
}
int main()
{
    char str[100];
    cout << "Enter String: ";
    cin >> str;
    if (isPalindrome(str))
        cout << "Yes";
    else
        cout << "No";
}
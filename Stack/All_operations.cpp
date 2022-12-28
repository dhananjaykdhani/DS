#include <iostream>
#define max_size_array = 8
using namespace std;

int stack[max_size_array];
int top = -1;

int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_ful()
{
    if (top == max_size_array)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int peek()
{
    return stack[top];
}

int pop()
{
    int data;
    if (!isempty())
    {
        data = stack[top];
        top--;
        return data;
    }

    else
    {
        cout << "Could not retrience data, stack is empty\n";
    }
}

int push(int data)
{
    if (!is_ful())
    {
        top = top + 1;
        stack[top] = data;
    }
    else
    {
        cout << "Could not insert data, Stack is full\n";
    }
}

int main()
{
    push(7);
    push(12);
    push(3);

    cout << "Element at the top of stack: " << peek() << endl;
    cout << "Element: \n";

    while (!isempty())
    {
        int data = pop();
        cout << data << endl;
        cout << "Address: " << &stack[top] << endl;
    }
}
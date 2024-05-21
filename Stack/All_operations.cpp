#include <iostream>
#define max_size_array 8
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
        cout<<"Element pushed: "<<data<<endl;
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
    push(9);
    push(5);
    push(1);
    push(8);
    push(2);
    push(4);
    push(6);
    cout << "Element at top of the stack: " << peek() << endl;
    if (top == -1)
    {
        cout << "Empty\n";
    }
    else
    {
        cout << "Stack: ";
        for (int i = 0; i <= top; i++)
        {
            cout << stack[i] << " ";
        }
    }
    pop();
    pop();
    pop();
    pop();
    pop();
}
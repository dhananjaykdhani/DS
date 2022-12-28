#include <iostream>
#define size 8
using namespace std;

int stack[size], top = -1;

void push(int data)
{
    if (top == size - 1)
    {
        cout << "Stack is full." << endl;
    }
    else
    {
        top++;
        stack[top] = data;
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "Stact is Empty." << endl;
    }
    else
    {
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        cout << "Stact is Empty.";
    }
    else
    {
        cout << "Peek of Stack is " << stack[top] << endl;
    }
}

void display()
{
    cout << "Elements of Stack are: ";
    for (int i = 0; i <= top; i++)
    {
        cout << stack[i] << " ";
    }
}

int main()
{
    push(5);
    push(3);
    push(9);
    pop();
    peek();
    display();
}
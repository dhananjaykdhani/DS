#include <iostream>
#define size 5
using namespace std;

int queue[size];
int front = -1, rear = -1;

void enquence(int data)
{
    if (rear == size - 1)
    {
        cout << "Overflow" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = data;
    }
}

void dequene()
{
    if (front == -1 && rear == -1)
    {
        cout << "Underflow" << endl;
    }
    else if (front == rear)
    {
        cout << "Element Deleted" << endl;
        front = rear = -1;
    }
    else
    {
        cout << "Element Deleted" << endl;
        front++;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue Elements are: ";
        for (int i = front; i < rear + 1; i++)
        {
            cout << queue[i] << " ";
        }
    }
}

void peek()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Peek of Queue is " << queue[front] << endl;
    }
}

int main()
{
    enquence(10);
    enquence(50);
    enquence(60);
    peek();
    dequene();
    enquence(50);
    enquence(10);
    enquence(15);
    enquence(5);
    display();
}

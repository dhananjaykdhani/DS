#include <iostream>
using namespace std;
#define size 6

int queue[size];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    if (rear == size - 1)
        cout << "Queue is full";
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = data;
    }
    else
    {
        rear++;
        queue[rear] = data;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
        cout << "Queue is empty";
    else if (front == rear)
        front = rear = -1;
    else
        front++;
}
void display()
{
    if (front == -1 && rear == -1)
        cout << "Queue is empty";
    else
    {
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
    }
}
int main()
{
    int choice, data;
    while (1)
    {
        cout << "1. Enqueue \n2. Dequeue \n3. Display \n4. Exit \nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            display();
            exit(0);
        default:
            cout << "Invalid choice";
        }
        cout << endl;
    }
    return 0;
}
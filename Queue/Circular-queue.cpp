#include <iostream>
#define size 6
using namespace std;

int queue[size], front = -1, rear = -1, x;

void enque(int data)
{
    if (front == (rear + 1) % size)
    {
        cout << "Queue Overflow.\n";
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        queue[(rear + 1) % size] = data;
        cout << data << " has been added in Queue as element.\n";
        rear = (rear + 1) % size;
    }
}

void deque()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue UnderFlow\n";
    }
    else
    {
        x = queue[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        cout << "Front Element " << x << " has been deleted from Queue\n";
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
        cout << "Queue Front element index is " << front << endl;
        cout << "Queue Elements are: " << endl;
        for (int i = front; i != rear; i = (i + 1) % size)
        {
            cout << i << ". " << queue[i] << endl;
        }
        cout << rear << ". " << queue[rear] << endl;
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
        cout << "Peek of Queue is " << queue[rear] << endl;
    }
}

void operaton()
{
    string x;
    cout << "\n\nChoose Your Operaion: \n\t1. enque \n\t2. deque \n\t3. peek \n\t4. display \n\t5. exit \n\t\t";
    cin >> x;
    if (x == "1" || x == "enque")
    {
        int i;
        cout << "Enter Your Element: ";
        cin >> i;
        enque(i);
        operaton();
    }
    else if (x == "2" || x == "deque")
    {
        deque();
        operaton();
    }
    else if (x == "3" || x == "peek")
    {
        peek();
        operaton();
    }
    else if (x == "4" || x == "display")
    {
        display();
        operaton();
    }
    else if (x == "5" || x == "exit")
    {
        cout << "Exited Form Queue.. \n";
    }
    else
    {
        cout << "Invalid Input..!!!\nChoose Again..\n";
        operaton();
    }
}

int main()
{
    operaton();
    display();
}
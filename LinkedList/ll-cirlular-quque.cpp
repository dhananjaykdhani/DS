// circular queue with link list

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class queue
{
    node *front;
    node *rear;

public:
    queue()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int x)
    {
        node *t = new node;
        if (t == NULL)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            t->data = x;
            t->next = NULL;
            if (front == NULL)
            {
                front = t;
                rear = t;
            }
            else
            {
                rear->next = t;
                rear = t;
            }
            rear->next = front;
        }
    }

    int dequeue()
    {
        int x = -1;
        node *p;
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            p = front;
            x = p->data;
            if (front == rear)
            {
                front = rear = NULL;
            }
            else
            {
                front = front->next;
                rear->next = front;
            }
            delete p;
        }
        return x;
    }

    void display()
    {
        node *p = front;
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != front);
        cout << endl;
    }
};

int main()
{
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.dequeue();
    q.display();
}
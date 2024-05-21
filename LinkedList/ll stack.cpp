//stack using Link list.
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class stack
{
    node *top;
public:
    stack()
    {
        top = NULL;
    }
    void push(int x)
    {
        node *t = new node;
        if(t == NULL)
            cout << "Stack is full" << endl;
        else
        {
            t->data = x;
            t->next = top;
            top = t;
        }
    }

    int pop()
    {
        int x = -1;
        if(top == NULL)
            cout << "Stack is empty" << endl;
        else
        {
            x = top->data;
            node *t = top;
            top = top->next;
            delete t;
        }
        return x;
    }

    void display()
    {
        node *p = top;
        while(p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main()
{
    stack stk;
    int choice, data;
    while(1)
    {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            stk.push(data);
            break;
        case 2:
            data = stk.pop();
            if(data != -1)
                cout << "Popped data is " << data << endl;
            break;
        case 3:
            stk.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
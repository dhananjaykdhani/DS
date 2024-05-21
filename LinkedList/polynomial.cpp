// polynomial through link list.

#include <iostream>
using namespace std;

class node
{
public:
    int coeff;
    int pow;
    node *next;

    node(int c, int p)
    {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

class polynomial
{
    node *head;

public:
    polynomial()
    {
        head = NULL;
    }

    void insertAtTail(int c, int p)
    {
        node *n = new node(c, p);
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }

    void print()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->coeff << "x^" << temp->pow << " + ";
            temp = temp->next;
        }
        cout << endl;
    }

    void add(polynomial p1, polynomial p2)
    {
        node *temp1 = p1.head;
        node *temp2 = p2.head;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->pow == temp2->pow)
            {
                int c = temp1->coeff + temp2->coeff;
                insertAtTail(c, temp1->pow);
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else if (temp1->pow > temp2->pow)
            {
                insertAtTail(temp1->coeff, temp1->pow);
                temp1 = temp1->next;
            }
            else
            {
                insertAtTail(temp2->coeff, temp2->pow);
                temp2 = temp2->next;
            }
        }
        while (temp1 != NULL)
        {
            insertAtTail(temp1->coeff, temp1->pow);
            temp1 = temp1

                        ->next;
        }
        while (temp2 != NULL)
        {
            insertAtTail(temp2->coeff, temp2->pow);
            temp2 = temp2->next;
        }
    }
};

int main()
{
    polynomial p1, p2, p3;
    p1.insertAtTail(1, 2);
    p1.insertAtTail(2, 1);
    p1.insertAtTail(3, 0);
    p1.print();
    p2.insertAtTail(1, 2);
    p2.insertAtTail(2, 1);
    p2.insertAtTail(3, 0);
    p2.print();
    p3.add(p1, p2);
    p3.print();
    return 0;
}

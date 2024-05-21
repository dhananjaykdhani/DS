#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

int length(node *&head)
{
    int len = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    if (head != NULL)
    {
        head->prev = temp;
    }
    head = temp;
}

void insertAtTail(node *&head, int data)
{
    if (head == NULL)
    {
        insertAtHead(head, data);
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *n = new node(data);
    temp->next = n;
    n->prev = temp;
}

void insertAtPositon(node *&head, int pos, int data)
{
    if (head == NULL || pos == 1)
    {
        insertAtHead(head, data);
        return;
    }
    else if (pos > length(head))
    {
        insertAtTail(head, data);
        return;
    }
    node *temp = head;
    int jump = 1;
    while (jump < pos - 1)
    {
        temp = temp->next;
        jump++;
    }
    node *n = new node(data);
    n->next = temp->next;
    n->prev = temp;
    temp->next->prev = n;
    temp->next = n;
}

void deleteAtHead(node *&head)
{
    if (head == NULL)
        return;

    node *temp = head;
    temp = temp->next;
    delete head;
    head = temp;
    head->prev = NULL;
}

void deleteAtTail(node *&head)
{
    if (head == NULL)
        return;

    node *temp = head;
    node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    delete temp;
    prev->next = NULL;
}

void deleteAtPosition(node *&head, int pos)
{
    if (head == NULL)
        return;
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    if (pos > length(head))
    {
        deleteAtTail(head);
        return;
    }
    node *temp = head;
    node *pre = NULL;
    int jump = 1;
    while (jump < pos - 1)
    {
        pre = temp;
        temp = temp->next;
        jump++;
    }
    temp->next->prev=pre;
    pre->next=temp->next;
    delete temp;
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);
    insertAtTail(head, 6);
    print(head);
    cout << length(head) << endl;
    cout << "Inserting at position 3" << endl;
    insertAtPositon(head, 3, 10);
    print(head);
    cout << "Deleting at head" << endl;
    deleteAtHead(head);
    print(head);
    cout << "Deleting at tail" << endl;
    deleteAtTail(head);
    print(head);
    deleteAtPosition(head,3);
    print(head);
    return 0;
}
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertAtHead(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
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
    node *a = new node(data);
    temp->next = a;
}

int length(node *&head)
{
    node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtPosition(node *&head, int pos, int data)
{
    if (head == NULL || pos == 0)
    {
        insertAtHead(head, data);
        return;
    }
    else if (pos > length(head))
    {
        insertAtTail(head, data);
        return;
    }
    else
    {
        int jump = 1;
        node *temp = head;
        while (jump < pos - 1)
        {
            temp = temp->next;
            jump++;
        }
        node *a = new node(data);
        a->next = temp->next;
        temp->next = a;
    }
}

void deleteAtHead(node *&head)
{
    if (head == NULL)
        return;

    node *temp = head;
    head = temp->next;
    delete temp;
}

void deleteAtTail(node *&head)
{
    if (head == NULL)
        return;

    node *prev = NULL;
    node *temp = head;

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
    if (head == NULL || pos < 1)
        return;

    else if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    else if (pos > length(head))
    {
        deleteAtTail(head);
        return;
    }
    int jump = 1;
    node *prev = NULL;
    node *temp = head;
    while (jump < pos)
    {
        prev = temp;
        temp = temp->next;
        jump++;
    }
    prev->next = temp->next;
    delete temp;
}

void search(node *&head, int data)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            cout << "Founded.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Not Founded.\n";
    return;
}

void sort(node *&head)
{
    int temp;
    if (head == NULL)
        return;
    node *next = NULL;
    node *prev = head;

    while (prev->next != NULL)
    {
        next = prev;
        while (next->next != NULL)
        {
            next = next->next;
            if (next->data < prev->data)
            {
                temp = next->data;
                next->data = prev->data;
                prev->data = temp;
            }
        }
        prev = prev->next;
    }
}

void mid(node *&head)
{
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Mid: " << slow->data << endl;
}

void bin_sea(node *&head, int key)
{
    node *temp = head;
    sort(temp);
    int low = 0;
    int high = length(head) - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (temp->data == key)
        {
            cout << "Founded.\n";
            return;
        }
        else if (temp->data > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        temp = temp->next;
    }
    cout << "Not Founded.\n";
    return;
}

int main()
{
    node *head = NULL;

    int choice, data, key;
    while (true)
    {
        cout << "1. Insert at head. \n2. Insert at Tail. \n3. Inser at Position. \n4. Delete at head. \n5. Delete at tail. \n6. Delete at position. \n7. Search. \n8. Display. \n9. Short. \n10. Binary Search. \n11. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Your data: ";
            cin >> data;
            insertAtHead(head, data);
            break;

        case 2:
            cout << "Enter Your data: ";
            cin >> data;
            insertAtTail(head, data);
            break;

        case 3:
            int pos;
            cout << "Enter Position: ";
            cin >> pos;
            cout << "Enter Your data: ";
            cin >> data;
            insertAtPosition(head, pos, data);
            break;

        case 4:
            deleteAtHead(head);
            break;

        case 5:
            deleteAtTail(head);
            break;

        case 6:
            cout << "Enter Position: ";
            cin >> pos;
            deleteAtPosition(head, pos);
            break;

        case 7:

            cout << "Enter Element to Search: ";
            cin >> key;
            search(head, key);

        case 8:
            print(head);
            cout << endl;
            break;

        case 9:
            sort(head);
            cout << endl;
            break;

        case 10:

            cout << "Enter Element to Search: ";
            cin >> key;
            bin_sea(head, key);
            break;

        case 11:
            return false;

        default:
            cout << "Invalid input.\n";
            break;
        }
    }
}
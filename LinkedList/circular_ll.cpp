// Circular Linked List

#include <iostream>
using namespace std;

class node{
public:
    int data;
    node *next;

    node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtHead(node *&head, int data){
    node *n = new node(data);
    node *temp = head;
    n->next = head;

    if(head != NULL){
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = n;
    }
    else{
        n->next = n;
    }
    head = n;
}

void insertAtTail(node *&head, int data){
    if(head == NULL){
        insertAtHead(head, data);
        return;
    }
    node *n = new node(data);
    node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void insertAtMiddle(node *&head, int data, int pos){
    if(head == NULL || pos == 0){
        insertAtHead(head, data);
    }
    else if(pos > length(head)){
        insertAtTail(head, data);
    }
    else{
        node *n = new node(data);
        node *temp = head;
        for(int i=0; i<pos-1; i++){
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    }
}

void deleteAtHead(node *&head){
    node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    node *toDelete = head;
    temp->next = head->next;
    head = head->next;
    delete toDelete;
}

void deleteAtTail(node *&head){
    node *temp = head;
    while(temp->next->next != head){
        temp = temp->next;
    }
    node *toDelete = temp->next;
    temp->next = head;
    delete toDelete;
}

void deleteAtMiddle(node *&head, int pos){
    if(pos == 0){
        deleteAtHead(head);
    }
    else if(pos >= length(head)){
        deleteAtTail(head);
    }
    else{
        node *temp = head;
        for(int i=0; i<pos-1; i++){
            temp = temp->next;
        }
        node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

int length(node *head){
    int len = 0;
    node *temp = head;
    while(temp->next != head){
        len++;
        temp = temp->next;
    }
    return len;
}

void print(node *head){
    node *temp = head;
    while(temp->next != head){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

int main(){
    node *head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtTail(head, 6);
    insertAtMiddle(head, 7, 3);
    print(head);
    deleteAtHead(head);
    print(head);
    deleteAtTail(head);
    print(head);
    deleteAtMiddle(head, 2);
    print(head);
    return 0;
}
// Queue usin Linked List
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
class Queue{
    node *front;
    node *rear;
public:
    Queue(){
        front = NULL;
        rear = NULL;
    }
    void enqueue(int data){
        node *n = new node(data);
        if(front == NULL){
            front = n;
            rear = n;
        }
        else{
            rear->next = n;
            rear = n;
        }
    }
    void dequeue(){
        if(front == NULL){
            cout << "Queue is empty" << endl;
            return;
        }
        else{
            node *temp = front;
            front = front->next;
            delete temp;
        }
    }
    int peek(){
        if(front == NULL){
            cout << "Queue is empty" << endl;
            return -1;
        }
        else{
            return front->data;
        }
    }
    bool isEmpty(){
        return front == NULL;
    }
    void print(){
        node *temp = front;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.print();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.print();
    cout << q.peek() << endl;
    cout << q.isEmpty() << endl;
    return 0;
}
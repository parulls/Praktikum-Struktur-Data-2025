#include <iostream>
using namespace std;

#define MAX 6 
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        cout << "Queue penuh\n";
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value; 
        cout << value << " masuk ke queue.\n";
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Kosong\n";
    } else {
        cout << queue[front] << " keluar dari queue.\n";
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        cout << "Queue Kosong\n";
    } else {
        cout << "Isi queue: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();

    enqueue(4);
    enqueue(5);

    display();

    enqueue(6);
    display();

    dequeue();
    display();

    return 0;
}

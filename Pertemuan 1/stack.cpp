#include <iostream>
using namespace std;

#define sizenya 4
int arr[sizenya];
int top = -1;

void push(int x){
    if (top == sizenya - 1){
        cout << "Stack Overflow";
        return;
    }
    arr[++top] = x;
}

int pop(){
    if (top == -1){
        cout << "Stack Underflow";
        return -1;
    }
    return arr[top--];
}

int tops(){
    if (top == -1){
        cout << "Stack Kosong";
        return -1;
    }
    return arr[top];
}

bool isEmpty(){
    return top == -1;
}

bool isFull(){
    return top == sizenya - 1;
}

int main (){
    push(1);
    push(2);
    push(3);
    push(4);

    for (int i = 0; i < sizenya; i++){
        cout << arr[i];
    }

    cout << "Elemen yang di pop : " << pop() << endl;

    cout << "Apakah stack kosong? " << (isEmpty() ? "Iya" : "Tidak");
    cout << endl;
    cout << "Apakah stack penuh? " << (isFull() ? "Iya" : "Tidak");
}





#include <iostream>
using namespace std;

#define capacity 4
int stack[capacity];
int top = -1;

void push(int x) {
    if (top == capacity - 1) {
    cout << "Stack Overflow\n";
    return;
    } 
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return stack[top--];
}


int main() {
    push(10); push(20); push(30); push(40); push(50);
    cout << pop() << " ";
    cout << pop() << " ";
    push(60);
    cout << pop() << " " ;
    cout << pop();
    return 0;
}
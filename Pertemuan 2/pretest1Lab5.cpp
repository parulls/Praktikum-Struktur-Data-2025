#include <iostream>
using namespace std;
#define capacity 3
int stack[capacity];
int top = -1;
void push(int x) {
    if (top == capacity - 1) return;
    stack[++top] = x;
}
int pop() {
    if (top == -1) return -1;
    return stack[top--];
}
int main() {
    push(5); push(15); push(25); push(35); pop(); push(45); pop();
    
    for (int i = 0; i <= top; i++) cout << stack[i] << " ";
    cout << endl;
    return 0;
}
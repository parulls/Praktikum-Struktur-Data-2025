#include <iostream>
#include <stack> //library stack STL
using namespace std;

void displayStack (stack<int> s){
    if (s.empty()){
        cout << "Stack Kosong";
        return;
    }
    while(!s.empty()){
        cout << s.top() <<endl;
        s.pop();
    }
}

int main () {
    stack<int> s;
    s.push(82);
    s.push(56);
    s.pop();
    s.push(43);
    s.push(11);
    s.pop();
    displayStack(s);
}
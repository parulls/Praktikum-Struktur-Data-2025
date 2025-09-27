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

    s.push(6);
    s.push(17);
    s.pop();

    displayStack(s);

    s.push(12);
    s.push(11);
    s.pop();

    displayStack(s);

    cout << "Ukuran stack: " << s.size() << endl;

    cout << "Pop: " << s.top() << endl;
    s.pop();

    cout << "Apakah stack kosong? " << (s.empty() ? "Iya" : "Tidak");
}
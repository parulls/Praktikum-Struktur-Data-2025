#include <iostream>
#include <queue>
using namespace std;

void displayqueue (queue<int> q){
    if (q.empty()){
        cout << "Queue Kosong";
        return;
    }
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}

int main () {
    queue<int> q;

    q.push(6);
    q.push(17);
    q.pop();

    displayqueue(q);
    cout << endl;
    q.push(12);
    q.push(11);
    q.pop();

    displayqueue(q);
    cout << endl;
    cout << "Ukuran queue: " << q.size() << endl;
}
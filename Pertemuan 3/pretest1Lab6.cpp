#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    s.push(5);
    s.push(15);
    s.push(25);
    s.pop();
    s.push(35);
    s.pop();
    s.push(45);
    s.push(55);

    cout << "Isi stac dari atas ke bawah: " << endl;
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
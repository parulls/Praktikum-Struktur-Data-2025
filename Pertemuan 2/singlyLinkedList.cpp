#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int new_data) {
        this->data = new_data;
        this->next = nullptr;
    }
};

int main() {
    
    // head dari linked list
    Node* head = new Node(10);

    // Menghubungkan node kedua
    head->next = new Node(20);

    // Menghubungkan node ketiga
    head->next->next = new Node(30);

    // Menghubungkan node keempat
    head->next->next->next = new Node(40);

    // menampilkan linked list
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}
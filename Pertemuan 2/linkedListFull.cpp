#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

void insertFirst(Node *&head, Node *&tail, int n) {
    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertLast(Node *&head, Node *&tail, int n) {
    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAfter(Node *&head, Node *&tail, int n, int check) {
    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        cout << "Linked list kosong, node ditambahkan sebagai head" << endl;
    } else {
        Node *p = head;
        while (p != NULL && p->value != check) {
            p = p->next;
        }
        if (p != NULL) {
            newNode->next = p->next;
            p->next = newNode;
            if (p == tail) {
                tail = newNode;
            }
            cout << "Node berhasil ditambahkan setelah " << check << endl;
        } else {
            cout << "Node dengan nilai " << check << " tidak ditemukan!" << endl;
            delete newNode;
        }
    }
}

void deleteAfter(Node *&head, Node *&tail, int check) {
    if (head == NULL) {
        cout << "Linked List is empty" << endl;
        return;
    }

    Node *p = head;
    while (p != NULL && p->value != check) {
        p = p->next;
    }

    if (p != NULL && p->next != NULL) {
        Node *temp = p->next;
        p->next = temp->next;
        if (temp == tail) {
            tail = p;
        }
        delete temp;
        cout << "Node setelah " << check << " berhasil dihapus" << endl;
    } else {
        cout << "Tidak ada node setelah " << check << " untuk dihapus" << endl;
    }
}

void deleteBefore(Node *&head, Node *&tail, int check) {
    if (head == NULL) {
        cout << "Linked List is empty" << endl;
        return;
    }

    if (head->value == check) {
        cout << "Tidak ada node sebelum head" << endl;
        return;
    }

    if (head->next != NULL && head->next->value == check) {
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Node sebelum " << check << " berhasil dihapus" << endl;
        return;
    }

    Node *p = head;
    while (p->next != NULL && p->next->next != NULL &&
           p->next->next->value != check) {
        p = p->next;
    }

    if (p->next != NULL && p->next->next != NULL) {
        Node *temp = p->next;
        p->next = temp->next;
        delete temp;
        cout << "Node sebelum " << check << " berhasil dihapus" << endl;
    } else {
        cout << "Node dengan nilai " << check << " tidak ditemukan!" << endl;
    }
}

void deleteMiddle(Node *&head, Node *&tail, int check) {
    if (head == NULL) {
        cout << "Linked List is empty" << endl;
        return;
    }

    if (head->value == check) {
        Node *temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        delete temp;
        cout << "Node dengan nilai " << check << " berhasil dihapus" << endl;
        return;
    }

    Node *p = head;
    while (p->next != NULL && p->next->value != check) {
        p = p->next;
    }

    if (p->next != NULL) {
        Node *temp = p->next;
        p->next = temp->next;
        if (temp == tail) {
            tail = p;
        }
        delete temp;
        cout << "Node dengan nilai " << check << " berhasil dihapus" << endl;
    } else {
        cout << "Node dengan nilai " << check << " tidak ditemukan!" << endl;
    }
}

void print(Node* head) {
    if (head == NULL) {
        cout << "Linked list kosong" << endl;
        return;
    }
    Node* temp = head;
    cout << "Isi linked list: ";
    while(temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteAll(Node *&head, Node *&tail) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
    cout << "Semua node berhasil dihapus" << endl;
}

void showMenu() {
    cout << "\n========== MENU LINKED LIST ==========" << endl;
    cout << "1. Tambah node di depan (insertFirst)" << endl;
    cout << "2. Tambah node di belakang (insertLast)" << endl;
    cout << "3. Tambah node setelah nilai tertentu (insertAfter)" << endl;
    cout << "4. Hapus node dengan nilai tertentu (deleteMiddle)" << endl;
    cout << "5. Hapus node setelah nilai tertentu (deleteAfter)" << endl;
    cout << "6. Hapus node sebelum nilai tertentu (deleteBefore)" << endl;
    cout << "7. Tampilkan isi linked list (print)" << endl;
    cout << "8. Hapus semua node (deleteAll)" << endl;
    cout << "0. Keluar" << endl;
    cout << "=======================================" << endl;
    cout << "Pilih menu (0-8): ";
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int choice, value, check;

    do {
        showMenu();
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> value;
                insertFirst(head, tail, value);
                cout << "Node berhasil ditambahkan di depan" << endl;
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> value;
                insertLast(head, tail, value);
                cout << "Node berhasil ditambahkan di belakang" << endl;
                break;
            case 3:
                cout << "Masukkan nilai baru: ";
                cin >> value;
                cout << "Masukkan nilai node yang dicari: ";
                cin >> check;
                insertAfter(head, tail, value, check);
                break;
            case 4:
                cout << "Masukkan nilai node yang akan dihapus: ";
                cin >> check;
                deleteMiddle(head, tail, check);
                break;
            case 5:
                cout << "Masukkan nilai node: ";
                cin >> check;
                deleteAfter(head, tail, check);
                break;
            case 6:
                cout << "Masukkan nilai node: ";
                cin >> check;
                deleteBefore(head, tail, check);
                break;
            case 7:
                print(head);
                break;
            case 8:
                deleteAll(head, tail);
                break;
            case 0:
                cout << "Program selesai. Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while(choice != 0);

    deleteAll(head, tail);

    return 0;
}

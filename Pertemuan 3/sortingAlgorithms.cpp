#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void append(int n) {
    Node* newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void printList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

void bubbleSort() {
    if (!head) return; // linked list kosong
    bool swapped; //untuk mengecek apakah udah ke swapped atau engga
    Node* ptr;
    Node* last = NULL;
    do {
        swapped = false;
        ptr = head;
        while (ptr->next != last) {
            if (ptr->value > ptr->next->value) {
                swap(ptr->value, ptr->next->value);
                swapped = true;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while (swapped);
}

void insertionSort() {
    if (!head || !head->next) return;
    Node* sorted = NULL;
    Node* curr = head;
    while (curr != NULL) {
        Node* next = curr->next;
        if (sorted == NULL || sorted->value >= curr->value) {
            curr->next = sorted;
            sorted = curr;
        } else {
            Node* p = sorted;
            while (p->next != NULL && p->next->value < curr->value) {
                p = p->next;
            }
            curr->next = p->next;
            p->next = curr;
        }
        curr = next;
    }
    head = sorted;
}

void selectionSort() {
    for (Node* i = head; i != NULL; i = i->next) {
        Node* minNode = i;
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (j->value < minNode->value) {
                minNode = j;
            }
        }
        swap(i->value, minNode->value);
    }
}

Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* result = NULL;
    if (left->value <= right->value) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

void split(Node* source, Node** front, Node** back) {
    Node* slow = source;
    Node* fast = source->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

Node* mergeSortRec(Node* node) {
    if (!node || !node->next) return node;
    Node* a; Node* b;
    split(node, &a, &b);
    a = mergeSortRec(a);
    b = mergeSortRec(b);
    return merge(a, b);
}

void mergeSort() {
    head = mergeSortRec(head);
}

Node* getTail(Node* cur) {
    while (cur != NULL && cur->next != NULL) cur = cur->next;
    return cur;
}

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = NULL, *cur = head, *tail = pivot;
    *newHead = NULL;

    while (cur != pivot) {
        if (cur->value < pivot->value) {
            if (*newHead == NULL) *newHead = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) prev->next = cur->next;
            Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
    if (*newHead == NULL) *newHead = pivot;
    *newEnd = tail;
    return pivot;
}

Node* quickSortRec(Node* head, Node* end) {
    if (!head || head == end) return head;
    Node *newHead = NULL, *newEnd = NULL;
    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->next != pivot) tmp = tmp->next;
        tmp->next = NULL;

        newHead = quickSortRec(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next = pivot;
    }
    pivot->next = quickSortRec(pivot->next, newEnd);
    return newHead;
}

void quickSort() {
    head = quickSortRec(head, getTail(head));
}

int main() {
    append(9);
    append(1);
    append(8);
    append(2);
    append(7);
    append(3);
    append(6);
    append(4);
    append(5);

    cout << "Linked List awal: ";
    printList();

    // bubbleSort();
    // insertionSort();
    // selectionSort();
    // mergeSort();
    quickSort();

    cout << "Setelah diurutkan: ";
    printList();

    return 0;
}
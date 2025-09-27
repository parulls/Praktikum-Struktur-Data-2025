#include <iostream>

using namespace std;

int main() {
    int size = 5;
    int* arr = new int[size];
    for(int i = 0; i < size; i++) {
        arr[i] = (i + 1) * (i + 2);
    }

    for(int i = size-1; i >= 0; i--) {
        cout << arr[i] << " ";
    }

    delete[] arr;
}
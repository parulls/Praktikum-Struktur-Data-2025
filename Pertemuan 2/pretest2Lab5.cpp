#include <iostream>
using namespace std;
int main() {
    int* arr = new int[4];
    for (int i = 0; i < 4; i++) {
        arr[i] = (i + 1) * (i + 2);
    }
    int* newArr = new int[6];
    for (int i = 0; i < 4; i++) {
        newArr[i] = arr[i];
    }
    newArr[4] = 30;
    newArr[5] = 42;
    
    for (int i = 0; i < 6; i++) {
        cout << newArr[i] << " ";
    }
    delete[] arr;
    delete[] newArr;
    return 0;
}
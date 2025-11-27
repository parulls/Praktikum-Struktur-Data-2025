#include <iostream>
#include <vector>
using namespace std;

int LinearSearch(vector<int>& arr, int x) {
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == x){
            return i;
        }
    }
    return -1; //menandakan data nya tidak ada
}

int main() {
    vector<int> arr = {10, 50, 30, 70, 20, 80, 60, 90, 40};
    int x;
    cout << "Masukkan angka yang mau dicari: ";
    cin >> x;
    int index = LinearSearch(arr, x);
    if (index == -1)
        cout << "data tidak ditemukan.";
    else
        cout << "data ditemukan di " << index;
    return 0;
}
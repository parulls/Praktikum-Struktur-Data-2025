#include <iostream>
#include <vector>
#include <algorithm> //untuk sorting
using namespace std;

int binarySearch(vector<int> &arr, int x) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high){
        int mid = low + (high - low)/2; //0 + (8 - 0)2 = 0 + 4 = 4

        if (arr[mid] == x){
            return mid;
        }

        if (arr[mid] < x){ //si x nya lebih besar
            low = mid + 1;
        }
        else { //si x nya lebih kecil
            high = mid - 1;
        }
    }
    return -1;
}


int main() {
    vector<int> arr = {10, 50, 30, 70, 80, 60, 20, 90, 40}; // 10 20 30 40 50 60 70 80 90
    int x, index;
    sort(arr.begin(), arr.end());
    cout << "Masukkan angka yang mau dicari: ";
    cin >> x;
    index = binarySearch(arr, x);
    if (index == -1)
        cout << "data tidak ditemukan.";
    else
        cout << "data ditemukan di " << index;
    return 0;
}


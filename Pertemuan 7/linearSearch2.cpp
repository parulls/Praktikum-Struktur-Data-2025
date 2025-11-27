#include <iostream>
#include <vector>
using namespace std;

//Jika ada lebih dari 1 nilai yang dicari

vector<int> LinearSearch(vector<int>& arr, int x) {
    vector <int> result;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == x){
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    vector<int> arr = {10, 50, 30, 70, 20, 80, 60, 20, 90, 40}; //ada 2 nilai 20
    int x;
    cout << "Masukkan angka yang mau dicari: ";
    cin >> x;
    vector<int> index = LinearSearch(arr, x); //menyimpan nilai akhir index
    if (index.empty())
        cout << "data tidak ditemukan.";
    else{
        cout << "Ditemukan di index ";
        for(int i : index)
            cout << i << ", ";
    }
    return 0;
}
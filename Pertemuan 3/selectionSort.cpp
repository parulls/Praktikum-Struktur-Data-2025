#include <iostream>
using namespace std;

int main (){
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int* data = new int[n];

    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++){
        cin >> data[i];
    }

    // Selection sort
    for (int i = 0; i < n - 1; i++){
        int minIndex = i;
        for (int j = i + 1; j < n; j++){
            if (data[j] < data[minIndex]){
                minIndex = j;
            }
        }
        int temp = data[i];
        data[i] = data[minIndex];
        data[minIndex] = temp;
    }

    cout << "Data setelah diurutkan dari terkecil hingga terbesar: ";
    for (int i = 0; i < n; i++){
        cout << data[i] << " ";
    }
    cout << endl;

    delete[] data;
    return 0;
}

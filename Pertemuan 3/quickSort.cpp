#include <iostream>
using namespace std;

int partition(int* arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++){
        if (arr[j] < pivot){ //ascending, kalau descending pakai >
            i++;
            int temp = arr[i]; //nukar i dan j
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1]; // nukar high dan i + 1
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int* arr, int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1); //mebandingkan low sampe pivot - 1
        quickSort(arr, pi + 1, high); // pivot + 1 sampe high
    }
}

int main(){
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int* data = new int[n];
    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++){
        cin >> data[i];
    }

    quickSort(data, 0, n - 1);

    cout << "Data setelah diurutkan dari terkecil hingga terbesar: ";
    for (int i = 0; i < n; i++){
        cout << data[i] << " ";
    }
    cout << endl;

    delete[] data;
    return 0;
}

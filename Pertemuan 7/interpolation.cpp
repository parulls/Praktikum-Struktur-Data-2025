#include <iostream>
#include <vector>
#include <algorithm> //dipake untuk sorting
using namespace std;

int interpolationSearch(vector<int>& arr, int lo, int hi, int x)
{
    int pos;
    if(lo <= hi && x >= arr[lo] && x <= arr[hi]){
        pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));

        if(arr[pos] == x)
            return pos;

        if (arr[pos] < x) //si x lebih besar
            interpolationSearch(arr, pos + 1, hi, x);
        
        if (arr[pos] > x) //si x lebih kecil
            interpolationSearch(arr, lo, pos - 1, x);
    }

    return -1;
}

int main()
{
    vector<int> arr = {10, 50, 30, 70, 80, 60, 20, 90, 40}; // 10 20 30 40 50 60 70 80 90
    arr = 15, 2, 7, 4, 9 ; key = 9;
    int x, index;
    sort(arr.begin(), arr.end());
    cout << "Masukkan angka yang mau dicari: ";
    cin >> x;
    index = interpolationSearch(arr, 0, arr.size() - 1, x);
    if (index == -1)
        cout << "data tidak ditemukan.";
    else
        cout << "data ditemukan di " << index;
    return 0;
}

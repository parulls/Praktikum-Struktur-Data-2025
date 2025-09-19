#include <iostream>
using namespace std;

int main (){
    int arr[3][2][2];

    for (int i = 0; i < 3; i++){
        for (int j= 0; j < 2; j++){
            for (int k = 0; k < 2; k++)
            {
                cout << "Masukkan nilai: ";
                cin  >> arr[i][j][k];
            }
        }
    }

    for (int i = 0; i < 3; i++){
        for (int j= 0; j < 2; j++){
            for (int k = 0; k < 2; k++){
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

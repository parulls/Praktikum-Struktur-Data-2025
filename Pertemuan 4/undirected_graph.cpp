#include <iostream>
#include <vector>

using namespace std;

class Graph{
private: 
    int numVertices; //banyaknya verteks atau titik (dipake untuk membuat adj matrix)
    vector<vector<int>> adjMatrix; //vektor didalam vektor (matriks)
    //{A, B, C, D, E} => bentuk vektor sesungguhnya
    //punya vektor isinya 5 : [0,1,2,3,4]

public: 
    Graph(int bykVertex){
        numVertices = bykVertex;

        //membuat adj matriks
        //memiliki dua parameter atau meminta 2 inputan
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }

    //mis: addEdge(1,2) => menambah hubungan antara (1 dan 2) dan (2 dan 1)
    void addEdge (int i, int j){
    if (i >= 0 && i < numVertices && j>= 0 && j < numVertices){
        adjMatrix[i][j] = 1; // A-B = 1
        adjMatrix[j][i] = 1; // B-A = 1, inilah yang menandakan kalau dia undirected/tidak berarah
    }
    else {
        cout << "Indeks verteks atau titiknya tidak valid/tidak ada"<<endl;
    }}

    //fungsi untuk print matriks/adjmatriks
    void printAdjMatrix(){
        for (int i = 0; i < numVertices; i++){
            for (int j = 0; j < numVertices; j++){
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main (){
    //definisikan graph yang mau kita buat
    Graph graphKomC(5); //ada 5 titik dalam graph ini

    //menambahkan edge/hubungan antara 1 titik ke titik lain
    graphKomC.addEdge(0,1); //0-1 atau 1-0 = 1
    graphKomC.addEdge(0,2); //0-2 atau 2-0 = 1
    graphKomC.addEdge(1,3); //1-3 atau 3-1 = 1
    graphKomC.addEdge(1,4);
    graphKomC.addEdge(2,3);
    graphKomC.addEdge(3,4);

    graphKomC.printAdjMatrix();

    return 0;
}
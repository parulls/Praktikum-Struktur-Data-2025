#include <iostream>
#include <vector>

using namespace std;

class Graph{
private: 
    int numberVertex;
    vector<vector<int>> adjMatrix;

public: 
    Graph(int banyakTitik){
        numberVertex = banyakTitik;
        adjMatrix.resize(numberVertex, vector<int>(numberVertex, 0));
    }

    //Fungsi untuk menambahkan hubungan tiap titik
    void addEdge(int i, int j, int weight){
        if (i>=0 && i < numberVertex && j>=0 && j < numberVertex){
            adjMatrix[i][j] = weight;
            adjMatrix[j][i] = weight; //untuk directed, ini dihapus
        }
        else{
            cout << "Indeks tidak valid";
        } 
    }

    //Fungsi untuk adjmatrix
    void printAdjMatrix(){
        for (int i = 0; i < numberVertex; i++){
            for (int j = 0; j < numberVertex; j++){
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl; 
        }
    }

};


int main (){
    Graph graphLab5(5); //indeks: 0,1,2,3,4

    graphLab5.addEdge(0,1,5);
    graphLab5.addEdge(0,2,3);
    graphLab5.addEdge(1,3,4);
    graphLab5.addEdge(1,4,7);
    graphLab5.addEdge(2,3,6);
    graphLab5.addEdge(3,4,8);

    graphLab5.printAdjMatrix();
}
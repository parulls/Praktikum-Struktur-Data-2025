#include <iostream>
#include <vector>


using namespace std;


class Graph {
private:
    int numVertices;
    vector<vector<int>> adjMatrix;


public:
    Graph(int V) {
        numVertices = V;
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }


    // Fungsi untuk menambahkan sisi BERBOBOT pada graf tak berarah
    void addEdge(int i, int j, int weight) { //ditambahkan bobot untuk parameter
        if (i >= 0 && i < numVertices && j >= 0 && j < numVertices) {
            adjMatrix[i][j] = weight; //nilai satu titik ke titik lain adalah bobotnya
            adjMatrix[j][i] = weight; // Karena ini graf tak berarah
        } else {
            cout << "Indeks simpul tidak valid." << endl;
        }
    }


    void printAdjMatrix() {
        cout << "Weighted Adjacency Matrix:" << endl;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};


int main() {
    Graph g(5);


    // addEdge(simpul1, simpul2, bobot)
    g.addEdge(0, 1, 5); // A-B dengan bobot 5
    g.addEdge(0, 2, 2); // A-C dengan bobot 2
    g.addEdge(1, 4, 6); // B-E dengan bobot 6
    g.addEdge(2, 3, 4); // C-D dengan bobot 4
    g.addEdge(3, 1, 3); // D-B dengan bobot 3
    g.addEdge(3, 4, 8); // D-E dengan bobot 8

    // Cetak adjacency matrix untuk melihat representasi graf
    g.printAdjMatrix();


    return 0;
}

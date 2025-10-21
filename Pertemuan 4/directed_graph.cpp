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


    // Fungsi untuk menambahkan sisi ke graf BERARAH
    void addEdge(int i, int j) {
        if (i >= 0 && i < numVertices && j >= 0 && j < numVertices) {
            adjMatrix[i][j] = 1; // Hanya satu arah, dari i ke j
        } else {
            cout << "Indeks simpul tidak valid." << endl;
        }
    }


    void printAdjMatrix() {
        cout << "Adjacency Matrix:" << endl;
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


    // Tambahkan sisi-sisi berarah
    g.addEdge(0, 0); // A -> A
    g.addEdge(0, 1); // A -> B
    g.addEdge(0, 2); // A -> C
    g.addEdge(1, 4); // B -> E
    g.addEdge(3, 1); // D -> B
    g.addEdge(3, 2); // D -> C
    g.addEdge(3, 4); // D -> E


    g.printAdjMatrix();


    return 0;
}

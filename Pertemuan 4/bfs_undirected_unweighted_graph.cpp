#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int numberVertex;
    vector<vector<int>> adjMatrix;

public:
    Graph(int V) {
        numberVertex = V;
        adjMatrix.resize(numberVertex, vector<int>(numberVertex, 0));
    }

    void addEdge(int i, int j) {
        if (i >= 0 && i < numberVertex && j >= 0 && j < numberVertex) {
            adjMatrix[i][j] = 1;
            adjMatrix[j][i] = 1;
        } else {
            cout << "Indeks simpul tidak valid." << endl;
        }
    }

    void printAdjMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < numberVertex; i++) {
            for (int j = 0; j < numberVertex; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void bfs(int startVertex) {
        vector<bool>visited(numberVertex, false);
        queue<int>titikVisit;

        //langsung ditandai visited
        visited[startVertex] = true;
        titikVisit.push(startVertex); //untuk menyimpan yang sudah dikunjungi

        while(!titikVisit.empty()){
            int currentVertex = titikVisit.front();
            titikVisit.pop();
            cout << currentVertex;

            for(int i = 0; i < numberVertex; i++){
                if(adjMatrix[currentVertex][i] == 1 && !visited[i]){
                    visited[i] = true;
                    titikVisit.push(i);
                }
            }
        }
        cout << endl;
    }
};


int main() {
    Graph graphLab5(8);
   
    // Parameter fungsi addEdge sekarang menerima angka sesuai gambar
    graphLab5.addEdge(0, 1);
    graphLab5.addEdge(0, 2);
    graphLab5.addEdge(1, 3);
    graphLab5.addEdge(1, 4);
    graphLab5.addEdge(2, 5);
    graphLab5.addEdge(3, 6);
    graphLab5.addEdge(4, 7);

    // Cetak adjacency matrix untuk melihat representasi graf
    graphLab5.printAdjMatrix();
    cout << endl;

    // Panggil fungsi bfs
    graphLab5.bfs(0);

    return 0;
}
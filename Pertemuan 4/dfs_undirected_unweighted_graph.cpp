#include <iostream>
#include <vector>


using namespace std;


class Graph {
private:
    int numVertices; //banyak baris dan kolom
    vector<vector<int>> adjMatrix; //di dalam vektor ada vektor lagi

public:
    Graph(int V) { 
        numVertices = V;
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0)); //parameter vektor: berapa baris dan isinya apa
    }


    void addEdge(int i, int j) {
        
        if (i >= 0 && i < numVertices && j >= 0 && j < numVertices) {
            adjMatrix[i][j] = 1;
            adjMatrix[j][i] = 1;
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

    void dfs(int startVertex) {
        vector<bool> visited(numVertices, false);
        dfsUtil(startVertex, visited);
    }


    void dfsUtil(int currentVertex, vector<bool>& visited) {
        visited[currentVertex] = true;
        cout << currentVertex << " ";
        for (int i = 0; i < numVertices; i++){
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]){
                dfsUtil(i, visited);
            }
        }
    }
};


int main() {
    Graph g(8);
   
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 6);
    g.addEdge(5, 7);


    // Cetak adjacency matrix untuk melihat representasi graf
    g.printAdjMatrix();
    cout << endl;

    // Panggil fungsi dfs
    g.dfs(0);
  
    return 0;  
}
#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int numberVertex; //banyak baris dan kolom
    vector<vector<int>> adjMatrix; //di dalam vektor ada vektor lagi

public:
    Graph(int V) { 
        numberVertex = V;
        adjMatrix.resize(numberVertex, vector<int>(numberVertex, 0)); //parameter vektor: berapa baris dan isinya apa
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

    void dfs(int startVertex) {
        vector<bool>visited(numberVertex, false);
        dfsUtil(startVertex, visited);
    }

    void dfsUtil(int currentVertex, vector<bool>& visited) {
        visited[currentVertex]=true;
        cout << currentVertex << " ";

        for (int i = 0; i < numberVertex; i++){
            if(adjMatrix[currentVertex][i] == 1 && !visited[i]){
                dfsUtil(i, visited);
            }
        }
    }
};


int main() {
    Graph graphLab5(8);
   
    graphLab5.addEdge(0, 1);
    graphLab5.addEdge(0, 2);
    graphLab5.addEdge(1, 3);
    graphLab5.addEdge(1, 4);
    graphLab5.addEdge(2, 5);
    graphLab5.addEdge(3, 6);
    graphLab5.addEdge(5, 7);

    // Cetak adjacency matrix untuk melihat representasi graf
    graphLab5.printAdjMatrix();
    cout << endl;

    // Panggil fungsi dfs
    graphLab5.dfs(0);
  
    return 0;  
}
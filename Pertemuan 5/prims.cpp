#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int cariVertexMinimum(vector<int> &cost, vector<int> &visited, int jumlahVertex){
    int minimumCost = INT_MAX;
    int indexMinimum = -1;

    for (int i = 0; i < jumlahVertex; i++){
        if (!visited[i] && cost[i] < minimumCost){
            minimumCost = cost[i];
            indexMinimum = i;
        }
    }

    return indexMinimum;
}

vector<int> algoritmaPrim (vector<vector<int>> &graph){
    int jumlahVertex = graph.size();
    vector<int> parent(jumlahVertex);
    vector<int> visited(jumlahVertex, false);
    vector<int> cost(jumlahVertex, INT_MAX);

    cost[0] = 0;
    parent[0] = -1;

    for (int edge = 0; edge < jumlahVertex - 1; edge++){
        int u = cariVertexMinimum(cost, visited, jumlahVertex);
        visited[u] = true;

        for(int v = 0; v < jumlahVertex; v++){
            if (graph[u][v] != 0 && !visited[v] && graph[u][v] < cost[v]){
                parent[v] = u;
                cost[v] = graph[u][v];
            }
        }
    }

    return parent;

}

void cetakHasil (vector<int> &parent, vector<vector<int>> &graph){
    int totalBobot = 0;

    for (int i = 1; i < parent.size(); i++){
        cout << parent[i] << " - " << i << "\t\t" << graph[parent[i]][i] <<endl;
        totalBobot += graph[parent[i]][i];
    }

    cout << "Total Bobot : " <<totalBobot <<endl;
}


int main (){
    vector<vector<int>> graph {
        { 0, 2, 0, 6, 0},
        { 2, 0, 3, 8, 5},
        { 0, 3, 0, 0, 7},
        { 6, 8, 0, 0, 9},
        { 0, 5, 7, 9, 0}
    };

    vector<int> parent = algoritmaPrim(graph);

    cetakHasil(parent, graph);

    return 0;
}

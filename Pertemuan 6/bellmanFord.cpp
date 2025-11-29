#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

struct edge{
    int asal, tujuan, bobot;
};

edge createEdge(int a, int t, int b){
    edge s;
    s.asal = a;
    s.tujuan = t;
    s.bobot = b;
    return s;
}

void bellmanFord(int jumlahVertex, vector<edge> &daftarEdge, int source){
    vector<int> jarak(jumlahVertex, INT_MAX);
    jarak[source] = 0;

    for(int i=0; i < jumlahVertex - 1; i++){
        for(int j = 0; j < daftarEdge.size(); j++){
            int u = daftarEdge[j].asal;
            int v = daftarEdge[j].tujuan;
            int w = daftarEdge[j].bobot;

            if(jarak[u] != INT_MAX && jarak[u] + w < jarak[v]){
            jarak[v] = jarak[u] + w;
        }
        }
    }

    cout << "Hasil Shortest Path dari " << source << ":\n";
    for(int i = 0; i < jumlahVertex; i++){
        if(jarak[i] == INT_MAX) 
            cout << "Node " << i << "Tidak dapat dijangkau\n";
        else
            cout << "Node " << i << ": " << jarak[i] << endl;
    }
}


int main(){
    int jumlahVertex = 6;
    vector<edge> daftarEdge;

    daftarEdge.push_back(createEdge(0, 1, 2));  //A-B
    daftarEdge.push_back(createEdge(0, 3, 8));  //A-D
    daftarEdge.push_back(createEdge(1, 4, 6));  //B-E
    daftarEdge.push_back(createEdge(1, 3, 5));  //B-D
    daftarEdge.push_back(createEdge(4, 3, 3));  //E-D
    daftarEdge.push_back(createEdge(4, 5, 1));  //E-F
    daftarEdge.push_back(createEdge(4, 2, 9));  //E-C
    daftarEdge.push_back(createEdge(3, 5, 2));  //D-F
    daftarEdge.push_back(createEdge(5, 2, 3));  //F-C

    bellmanFord(jumlahVertex, daftarEdge, 0);
    return 0;
}
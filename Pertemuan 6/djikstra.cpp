#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

typedef pair<int, int> PasanganDjikstra; //untuk menyimpan jarak dan node

void djikstra(int jumlahVertex, vector<vector<PasanganDjikstra>> &graf, int source){
    vector<int> jarak(jumlahVertex, INT_MAX);
    vector<bool> visited(jumlahVertex, false);

    priority_queue<PasanganDjikstra, vector<PasanganDjikstra>, greater<PasanganDjikstra>> pq;

    jarak[source] = 0;
    pq.push({0, source});

    while(!pq.empty()){
        int jarakSaatIni = pq.top().first;
        int nodeSaatIni = pq.top().second;
        pq.pop();

        if(visited[nodeSaatIni]) continue;
        visited[nodeSaatIni] = true;

        for(auto &tetangga : graf[nodeSaatIni]){
            int nodeTetangga = tetangga.first;
            int bobotEdge = tetangga.second;

            if(!visited[nodeTetangga] && jarak[nodeSaatIni] + bobotEdge < jarak[nodeTetangga]){
                jarak[nodeTetangga] = jarak[nodeSaatIni] + bobotEdge;
                pq.push({jarak[nodeTetangga], nodeTetangga});
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
    vector<vector<PasanganDjikstra>> graf(jumlahVertex);

    graf[0].push_back({1, 2});  //A-B
    graf[0].push_back({3, 8});  //A-D
    graf[1].push_back({4, 6});  //B-E
    graf[1].push_back({3, 5});  //B-D
    graf[4].push_back({3, 3});  //E-D
    graf[4].push_back({5, 1});  //E-F
    graf[4].push_back({2, 9});  //E-C
    graf[3].push_back({5, 2});  //D-F
    graf[5].push_back({2, 3});  //F-C

    djikstra(jumlahVertex, graf, 0);

    return 0;
}
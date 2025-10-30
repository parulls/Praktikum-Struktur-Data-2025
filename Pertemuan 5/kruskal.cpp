#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int jumlahVertex) {
        parent.resize(jumlahVertex);
        rank.resize(jumlahVertex);
        for (int i = 0; i < jumlahVertex; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int cariParent(int vertex) {
        if (parent[vertex] == vertex) {
            return vertex;
        }
        return parent[vertex] = cariParent(parent[vertex]);
    }

    void gabungkanSet(int vertex1, int vertex2) {
        int parent1 = cariParent(vertex1);
        int parent2 = cariParent(vertex2);
        if (parent1 == parent2) {
            return;
        }
        if (rank[parent1] < rank[parent2]) {
            parent[parent1] = parent2;
        } else if (rank[parent1] > rank[parent2]) {
            parent[parent2] = parent1;
        } else {
            parent[parent2] = parent1;
            rank[parent1]++;
        }
    }
};

bool urutkanBerdasarkanBobot(vector<int> &e1, vector<int> &e2) {
    return e1[2] < e2[2];
}

int algoritmaKruskal(int jumlahVertex, vector<vector<int>> &edges) {
    cout << "\n=== ALGORITMA KRUSKAL ===" << endl;
    cout << "Jumlah Vertex: " << jumlahVertex << endl;
    cout << "Jumlah Edge: " << edges.size() << endl;

    sort(edges.begin(), edges.end(), urutkanBerdasarkanBobot);

    cout << "\nEdge setelah diurutkan berdasarkan bobot:" << endl;
    cout << "From\tTo\tBobot" << endl;
    cout << "-------------------------" << endl;
    for (auto &e : edges) {
        cout << e[0] << "\t" << e[1] << "\t" << e[2] << endl;
    }

    DisjointSet ds(jumlahVertex);

    int totalBobot = 0;
    int jumlahEdgeDipilih = 0;

    cout << "\nProses pemilihan edge:" << endl;
    cout << "-------------------------" << endl;

    for (auto &edge : edges) {
        int dari = edge[0];
        int ke = edge[1];
        int bobot = edge[2];

        if (ds.cariParent(dari) != ds.cariParent(ke)) {
            ds.gabungkanSet(dari, ke);
            totalBobot += bobot;
            jumlahEdgeDipilih++;
            cout << "Pilih edge " << dari << "-" << ke
                 << " (bobot: " << bobot << ")" << endl;
            if (jumlahEdgeDipilih == jumlahVertex - 1) {
                break;
            }
        } else {
            cout << "Skip edge " << dari << "-" << ke
                 << " (bobot: " << bobot << ") - membentuk cycle" << endl;
        }
    }

    cout << "\n=== HASIL AKHIR ===" << endl;
    cout << "Total bobot MST: " << totalBobot << endl;
    cout << "Jumlah edge dalam MST: " << jumlahEdgeDipilih << endl;

    return totalBobot;
}

int main() {
    vector<vector<int>> edges = {
        {0, 1, 10},
        {1, 3, 15},
        {2, 3, 4},
        {2, 0, 6},
        {0, 3, 5}
    };

    int jumlahVertex = 4;
    int hasilMST = algoritmaKruskal(jumlahVertex, edges);
    cout << "\n>>> Total bobot Minimum Spanning Tree: " << hasilMST << endl;

    return 0;
}

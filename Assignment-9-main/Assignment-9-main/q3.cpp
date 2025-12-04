#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int u, v, w;
};

class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i] = i;
    }

    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) parent[b] = a;
    }
};

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {2,3,4}
    };

    sort(edges.begin(), edges.end(), 
        [](Edge a, Edge b){ return a.w < b.w; });

    DSU dsu(V);
    int mstCost = 0;

    cout << "Edges in MST (Kruskal):\n";
    for(auto &e : edges) {
        if(dsu.find(e.u) != dsu.find(e.v)) {
            dsu.unite(e.u, e.v);
            mstCost += e.w;
            cout << e.u << " - " << e.v << " (" << e.w << ")\n";
        }
    }

    cout << "Total Cost: " << mstCost;
}

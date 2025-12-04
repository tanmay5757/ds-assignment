#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int,int>>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w}); // undirected
    }

    void dijkstra(int src) {
        vector<int> dist(V, 1e9);
        dist[src] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,src});

        while(!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            for(auto &nbr : adj[node]) {
                int next = nbr.first;
                int weight = nbr.second;

                if(dist[node] + weight < dist[next]) {
                    dist[next] = dist[node] + weight;
                    pq.push({dist[next], next});
                }
            }
        }

        cout << "Shortest distances from " << src << ":\n";
        for(int i=0;i<V;i++)
            cout << "Node " << i << " : " << dist[i] << endl;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0,1,2);
    g.addEdge(0,2,4);
    g.addEdge(1,2,1);
    g.addEdge(1,3,7);
    g.addEdge(2,4,3);

    g.dijkstra(0);

    return 0;
}

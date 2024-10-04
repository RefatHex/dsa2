#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
int V, E;

void dijkstra(vector<vector<pair<int, int>>>& adj, int source) {
    vector<int> dist(V, INF);  // Distance array
    vector<bool> visited(V, false);  // Visited array
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});  // {distance, node}

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Output the distances
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) {
            cout << i << " is unreachable from the source." << endl;
        } else {
            cout << i << " " << dist[i] << endl;
        }
    }
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<pair<int, int>>> adj(V);  // Adjacency list

    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cout << "Enter start node, end node and weight: ";
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});  // Comment this line for directed graph
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    dijkstra(adj, source);

    return 0;
}

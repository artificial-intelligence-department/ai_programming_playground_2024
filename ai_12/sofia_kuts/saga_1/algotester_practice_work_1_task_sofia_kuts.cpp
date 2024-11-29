#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to, weight;
    Edge(int to, int weight) : to(to), weight(weight) {}
};

vector<int> dijkstra(int n, int start, const vector<vector<Edge> >& graph) {
    vector<int> dist(n + 1, INT_MAX);
    dist[start] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(pair<int, int>(0, start)); 
    while (!pq.empty()) {
        pair<int, int> top = pq.top(); pq.pop();
        int d = top.first, u = top.second;
        
        if (d > dist[u]) continue;

        for (size_t i = 0; i < graph[u].size(); ++i) {
            const Edge& edge = graph[u][i];
            int v = edge.to, w = edge.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(pair<int, int>(dist[v], v)); 
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge> > graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(Edge(b, c)); 
        graph[b].push_back(Edge(a, c)); 
    }

    vector<int> distances = dijkstra(n, 1, graph);

    int total_distance = 0;
    for (int i = 2; i <= n; ++i) {
        total_distance += distances[i];
    }

    cout << total_distance << endl;

    return 0;
}

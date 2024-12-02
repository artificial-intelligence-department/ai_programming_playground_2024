#include<bits/stdc++.h>

using namespace std;

int find_vertex(int n, int vertex, const vector<vector<int>> &graph) {
    queue<int> q;
    vector<int> dist(n + 1, 1000);
    dist[vertex] = 0;
    for (auto i: graph[vertex]) {
        q.push(i);
        dist[i] = 1;
    }
    int result = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto i: graph[cur]) {
            if (dist[i] == 1000) {
                q.push(i);
                dist[i] = dist[cur] + 1;
                result++;
            }
        }
    }
    return (result);
}

void find_vertexes(int my_vertex, int n, int vertex, const vector<vector<int>> &graph) {
    queue<int> q;
    vector<int> dist(n + 1, 1000);
    dist[vertex] = 0;
    for (auto i: graph[vertex]) {
        q.push(i);
        dist[i] = 1;
    }
    int result = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto i: graph[cur]) {
            if (dist[i] == 1000) {
                q.push(i);
                dist[i] = dist[cur] + 1;
                cout << my_vertex << " " << cur << " " << i << endl;
            }
        }
    }
}

int main() {
    int n, x, y;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int result = 1e7, vertex;
    for (int i = 1; i <= n; i++) {
        int rez = find_vertex(n, i, graph);
        if (result > rez) {
            result = rez;
            vertex = i;
        }
    }
    cout << result << endl;
    find_vertexes(vertex, n, vertex, graph);
}



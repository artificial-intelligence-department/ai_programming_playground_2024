#include<bits/stdc++.h>

using namespace std;
const int inf = 2e8;
//2133 Катеринка
void dijkstra(set<pair<int, int>> &que, const vector<vector<pair<int, int>>> &graph, vector<int> &dist) {
    while (!que.empty()) {

        int cur = que.begin()->second;
        que.erase(que.begin());
        for (auto curent: graph[cur]) {
            if (dist[curent.first] > dist[cur] + curent.second) {
                que.erase({dist[curent.first], curent.first});
                dist[curent.first] = dist[cur] + curent.second;
                que.insert({dist[curent.first], curent.first});
            }
        }
    }
}

int main() {
    int n, m, q, kat, from, to, d;
    cin >> n >> m >> q >> kat;
    vector<int> dist(n, inf);
    vector<vector<pair<int, int>>> graph(n);
    set<pair<int, int>> que;
    vector<pair<int, int>> find(q);
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> d;
        graph[from - 1].push_back({to - 1, d});
        graph[to - 1].push_back({from - 1, d});
    }
    for (int i = 0; i < q; i++) {
        cin >> find[i].first >> find[i].second;
    }
    kat--;
    que.insert({0, kat});
    dist[kat] = 0;
    dijkstra(que, graph, dist);
    for (int i = 0; i < q; i++) {
        cout << dist[find[i].first - 1] + dist[find[i].second - 1] << endl;
    }
}



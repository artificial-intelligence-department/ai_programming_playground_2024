#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

//0606
//сніг

const double INF = 1e9;

struct Edge {
    int u, v;
    double weight;
};

int n;
int parent[100];
Edge edges[5000];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY)
        parent[rootX] = rootY;
}

double findD(int i, int j, int x[], int y[]) {
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

int main() {
    cin >> n;
    int x[n], y[n];

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        parent[i] = i;
    }

    int edgeCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges[edgeCount].u = i;
            edges[edgeCount].v = j;
            edges[edgeCount].weight = findD(i, j, x, y);
            edgeCount++;
        }
    }

    sort(edges, edges + edgeCount, [](Edge &a, Edge &b) {
        return a.weight < b.weight;
    });

    double totalWeight = 0;
    int edgesUsed = 0;

    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        double w = edges[i].weight;

        if(find(u) == find(v)){
            continue;
        }
        else if (find(u) != find(v)) {
            unionSets(u, v);
            totalWeight += w;
            edgesUsed++;
            if (edgesUsed == n - 1) break;
        }
    }

    cout.precision(7);
    cout << fixed << totalWeight << endl;

    return 0;
}
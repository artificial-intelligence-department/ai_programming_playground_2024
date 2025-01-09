#include <bits/stdc++.h>

using namespace std;
//1225 Найкоротший шлях 2
int main() {
    int n, m, x, y;
    cin >> n >> m;

    vector<vector<long long>> a;
    long long inf = 1e14;
    vector<vector<int>> grap(n);
    long long l;
    for (int i = 0; i < m; i++) {

        cin >> x >> y >> l;
        a.push_back({x - 1, y - 1, l});
        grap[x - 1].push_back(y - 1);
    }

    vector<long long> d(n, inf);
    d[0] = 0;
    vector<bool> was(n,false);
    was[0]=true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int to = a[j][1];
            int fro = a[j][0];
            long long le = a[j][2];
            if ((d[to] > d[fro] + le) && (was[fro])) {
                was[to] = true;
                d[to] = d[fro] + le;
            }
        }
    }

    queue<int> q;
    for (int j = 0; j < m; j++) {
        int to = a[j][1];
        int fro = a[j][0];
        long long le = a[j][2];
        if ((d[to] > d[fro] + le)&&(was[fro])) {
            d[to] = min(d[to], d[fro] + le);
            q.push(to);
        }
    }

    vector<bool> visited(n, true);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        d[cur] = -inf;
        visited[cur] = false;
        for (int i : grap[cur]) {
            if (visited[i]) {
                visited[i]=false;
                q.push(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (d[i] == -inf) {
            printf("-inf ");
        } else if (d[i] == inf) {
            printf("inf ");
        } else {
            printf("%lld ",d[i]);
        }
    }
}






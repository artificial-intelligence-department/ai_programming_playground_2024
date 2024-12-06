#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 100005;

vector<int> graph[MAXN];
int team[MAXN]; 

bool bfs(int n) 
{
    for (int i = 1; i <= n; ++i) 
    {
        if (team[i] == 0) 
        {  
            team[i] = 1; 
            queue<int> q;
            q.push(i);

            while (!q.empty()) 
            {
                int curr = q.front();
                q.pop();

                for (int neighbor : graph[curr]) 
                {
                    if (team[neighbor] == 0) {
                        team[neighbor] = 3 - team[curr];
                        q.push(neighbor);
                    }
                    else if (team[neighbor] == team[curr]) 
                    {
                        return false;  
                    }
                }
            }
        }
    }
    return true;
}

int main() 
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if (!bfs(n)) {
        cout << "Impossible" << endl;
    }
    else {
        for (int i = 1; i <= n; ++i) {
            cout << team[i];
        }
        cout << endl;
    }

    return 0;
}






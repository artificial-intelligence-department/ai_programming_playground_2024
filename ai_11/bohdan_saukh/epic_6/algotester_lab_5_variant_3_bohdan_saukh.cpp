#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Cell{
    int x, y, height;
};

int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--;
    y--;

    vector<vector<int>> matrix(n, vector<int>(m, -1));
    queue<Cell> q;

    matrix[x][y] = max(((n-1) - x + (m-1) - y), max((x + y), max((y + (n-1) - x), (x + (m-1) - y))));
    q.push({x, y, matrix[x][y]});

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()){
        Cell current = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && matrix[nx][ny] == -1){
                matrix[nx][ny] = current.height - 1;
                q.push({nx, ny, matrix[nx][ny]});
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


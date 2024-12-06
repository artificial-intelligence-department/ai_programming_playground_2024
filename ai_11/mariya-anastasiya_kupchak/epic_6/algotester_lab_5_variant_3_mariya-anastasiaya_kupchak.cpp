#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Cell
{
    int x, y, height;
};

int main()
{
    int N, M, x, y;
    cin >> N >> M;
    cin >> x >> y;

    x--;
    y--;

    int peak_height = max(x, N - 1 - x) + max(y, M - 1 - y);

    vector<vector<int>> map(N, vector<int>(M, -1));

    vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    queue<Cell> qu;
    qu.push({x,y,peak_height});
    map[x][y] = peak_height;

    while(!qu.empty())
    {
        Cell current = qu.front();
        qu.pop();

        for (auto [dx, dy] : directions) 
        {
            int X = current.x + dx;
            int Y = current.y + dy;

            if (X >= 0 && X < N && Y >= 0 && Y < M && map[X][Y] == -1) 
            {
                map[X][Y] = current.height - 1;
                qu.push({X, Y, current.height - 1});
            }
        }
    }

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}

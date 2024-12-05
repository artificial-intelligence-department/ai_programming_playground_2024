#include <iostream>
#include <queue>
#include <utility>
#include <vector>
int main()
{
    int n, m;
    std::cin >> n >> m;
    int x, y;
    std::cin >> x >> y;
    x--, y--;

    std::vector<std::vector<int>> heightMap(n, std::vector<int>(m, -1));
    std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    std::queue<std::pair<int, int>> q;
    q.push({x, y});
    heightMap[x][y] = 0;

    int maxHeight = 0;

    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();
        for (auto [dx, dy] : directions)
        {
            int nx = cx + dx, ny = cy + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && heightMap[nx][ny] == -1)
            {
                heightMap[nx][ny] = heightMap[cx][cy] + 1;
                maxHeight = std::max(maxHeight, heightMap[nx][ny]);
                q.push({nx, ny});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << maxHeight - heightMap[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}

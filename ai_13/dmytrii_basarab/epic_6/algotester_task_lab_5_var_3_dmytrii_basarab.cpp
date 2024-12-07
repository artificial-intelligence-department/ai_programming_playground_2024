#include <iostream>
#include <queue>
#include <utility>//для pair
#include <vector>

using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    x--;
    y--;

    vector<vector<int>> heightMap(n, vector<int>(m, -1));
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    queue<pair<int, int>> q;
    heightMap[x][y] = 0;
    int maxHeight = 0;

    q.push({x, y});

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
    while (!q.empty())
    {
        auto [cx, cy] = q.front();//взяти перший елемент з черги куди ми підем
        q.pop();
        for (auto [dx, dy] : directions) //перебирає directions
        {
            int nx = cx + dx;
            int ny = cy + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && heightMap[nx][ny] == -1)
            {// знаходе шляхти шоб не вийти за межі карти і іти на ше не відвідану вершину
                heightMap[nx][ny] = heightMap[cx][cy] + 1;//бере значення з тої точки звідки прийшов
                maxHeight = heightMap[nx][ny];
                q.push({nx, ny});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << maxHeight - heightMap[i][j] << ' ';
        }//таке як реверс шоб в нашій старій карті найбільше значення стало 0 а найвище maxheight
        cout << endl;
    }

    return 0;
}
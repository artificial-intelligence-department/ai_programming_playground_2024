#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    int sum = max(n - x, x - 1) + max(m - y, y - 1);
    //відстань від нижньої межі, від верхньої межі, від правої межі, від лівої межі
    x -= 1;
    y -= 1;
    matrix[x][y] = sum;

    for (int i = y + 1; i < m; i++) // вправо
        matrix[x][i] = matrix[x][i - 1] - 1;
    for (int i = y - 1; i >= 0; i--) // вліво
        matrix[x][i] = matrix[x][i + 1] - 1;
    for (int i = x - 1; i >= 0; i--) // вверх ряд
        for (int iy = 0; iy < m; iy++)
            matrix[i][iy] = matrix[i + 1][iy] - 1;
    for (int i = x + 1; i < n; i++) // вниз ряд
        for (int iy = 0; iy < m; iy++)
            matrix[i][iy] = matrix[i - 1][iy] - 1;

    for (vector<int> arr : matrix)
    {
        for (int el : arr)
            cout << el << " ";
        cout << endl;
    }

    return 0;
}
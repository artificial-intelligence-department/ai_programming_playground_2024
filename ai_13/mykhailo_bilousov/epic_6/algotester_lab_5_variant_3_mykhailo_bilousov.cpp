#include <iostream>
#include <cmath>

#define MANH(x1, y1, x2, y2) (abs((x2)-(x1))+abs((y2)-(y1)))
#define MAX(x,y) ((x)>(y)?(x):(y))

void fill_array(int** arr, int n, int m, int x, int y, int value)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            arr[i][j] = value - abs(x-i) - abs(y-j);
        }
    }
}

int main()
{
    int n, m, x, y;
    std::cin >> n >> m;
    std::cin >> x >> y;
    x--; // 0-based arrays
    y--; // 0-based arrays
    int** arr = new int*[n]; 
    for(int i = 0; i < n; i++) arr[i] = new int[m];

    int peak = MAX(MAX(MAX(MANH(x, y, n-1, m-1), MANH(x, y, 0, m-1)), MANH(x, y, n-1, 0)), MANH(x, y, 0, 0));
    fill_array(arr, n, m, x, y, peak);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) std::cout << arr[i][j] << " ";
        std::cout << std::endl;
    }
}
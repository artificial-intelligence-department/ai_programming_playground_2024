#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    int N,M;
    int x,y;
    std::cin >> N >> M;
    std::cin >> x >> y;
    std::vector<std::vector<int>> mount(N, std::vector<int>(M, 0));
    x--; y--;
    int peakHeight = std::max(x, N - 1 - x) + std::max(y, M - 1 - y);
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            mount[i][j] = peakHeight - (abs(x - i) + abs(y - j));
        }
    }
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < M; ++j) 
        {
            std::cout << mount[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
#include <iostream>
#include <cmath>
#include <algorithm>

int main()
{
    int N, M;
    std::cin >> N >> M;

    int x, y;
    std::cin >> x >> y;

    int** height = new int*[N];
    for (int i = 0; i < N; ++i) {
        height[i] = new int[M];
    }
    int max_value = std::max(N - x, x - 1) + std::max(M - y, y - 1);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            height[i][j] = max_value - (std::abs(i - (x - 1)) + std::abs(j - (y - 1)));
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << height[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < N; ++i) {
        delete[] height[i];
    }
    delete[] height;

    return 0;
}
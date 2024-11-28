#include <iostream>
#include <algorithm>

int main()
{
    int N, M;
    std::cin >> N >> M;
    int x, y;
    std::cin >> x >> y;
    int max_value = std::max(N - x, x - 1) + std::max(M - y, y - 1);
    
    int arr[N][M];
    for(int i = 0; i < N; i++) 
        {
            int current_row = max_value - abs(i - x + 1);
            for (int j = 0; j < M; j++)
            {
                int current_col = abs(j - y + 1);
                arr[i][j] = current_row - current_col;
            }
        }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
            std::cout << arr[i][j] << " ";
        std::cout << std::endl;
    }


    return 0;
}


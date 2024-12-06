#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int peakX, peakY;
    cin >> peakX >> peakY;


    peakX -= 1;
    peakY -= 1;

    vector<vector<int>> heightMap(N, vector<int>(M, 0));

    int maxHeight = max(peakX, N - 1 - peakX) + max(peakY, M - 1 - peakY);

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < M; ++col)
        {
            int verticalDist = abs(peakX - row);
            int horizontalDist = abs(peakY - col);

            heightMap[row][col] = maxHeight - (verticalDist + horizontalDist);
        }
    }

    for (const auto& row : heightMap)
    {
        for (const auto& cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}

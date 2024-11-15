#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> matrix(N, vector<int>(M));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int maxSum = INT_MIN;

    for(int i = 0; i <= N - 3; i++)
    {
        for(int j = 0; j <= M - 3; j++)
        {
            int sum = 0;
            for(int k = 0; k < 3; k++)
            {
                for(int l = 0; l < 3; l++)
                {
                    sum += matrix[i+k][j+l];
                }
            }

            maxSum = max(maxSum, sum);
        }
    }

    cout << maxSum << "\n";

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<char>> b(N, vector<char>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> b[i][j];
        }
    }
    for (int j = 0; j < M; j++)
    {
        for (int i = N - 1; i >= 0; i--)
        {
            if (b[i][j] == 'S')
            {
                int col = i;
                while (col + 1 < N && b[col + 1][j] == 'O')
                {
                    col++;
                }
                if (col != i)
                {
                    swap(b[i][j], b[col][j]);
                }
            }
        }
    }
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << b[i][j];
        }
        cout << endl;
    }
}
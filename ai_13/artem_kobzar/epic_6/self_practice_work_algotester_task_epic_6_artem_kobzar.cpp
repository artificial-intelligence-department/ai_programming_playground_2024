#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<char>> cave(N, vector<char>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> cave[i][j];
        }
    }
    for (int j = 0; j < M; j++)
    {
        for (int i = N - 1; i >= 0; i--)
        {
            if (cave[i][j] == 'S')
            {
                int col = i;
                while (col + 1 < N && cave[col + 1][j] == 'O')
                {
                    col++;
                }
                if (col != i)
                {
                    swap(cave[i][j], cave[col][j]);
                }
            }
        }
    }
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << cave[i][j];
        }
        cout << endl;
    }
}
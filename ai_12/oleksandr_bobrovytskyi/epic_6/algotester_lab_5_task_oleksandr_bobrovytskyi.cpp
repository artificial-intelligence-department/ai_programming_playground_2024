#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, emptyRow;

    cin >> N >> M;

    if(N < 1 || N > 1000 || M < 1 || M > 1000)
    {
        return 1;
    }

    vector<string> cave(N);

    for(int i = 0; i < N; i++)
    {
        cin >> cave[i];
        if(cave[i].size() != M)
        {
            return 1;
        }
    }

    for(int j = 0; j < M; j++)
    {
        emptyRow = N - 1;
        for(int i = N - 1; i >= 0; i--)
        {
            if(cave[i][j] == 'X')
            {
                emptyRow = i - 1;
            }
            else if(cave[i][j] == 'S')
            {
                cave[i][j] = 'O';
                cave[emptyRow][j] = 'S';
                emptyRow--;
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
       cout << cave[i] << endl; 
    }

    return 0;
}
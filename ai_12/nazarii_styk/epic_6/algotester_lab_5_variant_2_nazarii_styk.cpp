#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int M; // висота
    int N; // ширина
    do
    {
    cin >> M >> N;;
    }while(!(N >= 1 && N <= 1000 && M >= 1 && M <= 1000));

    vector<vector<char>> cave(M, vector<char>(N));

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char material;
            cin >> material;
            if (material == 'S' || material == 'O' || material == 'X')
            {
                cave[i][j] = material;
            }
        }
    }

    for (int i = M - 2; i >= 0; i--) // M-2, бо останній рядок не обробляється
    {
        for (int j = 0; j < N; j++) 
        {
            if (cave[i][j] == 'S') 
            {
                int k = i; 
                while (k + 1 < M && cave[k + 1][j] == 'O') 
                {
                    cave[k + 1][j] = 'S';
                    cave[k][j] = 'O';
                    k++;
                }
            }
        }
    }
    cout << endl;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << cave[i][j];
        } 
        cout << endl;
    }
}

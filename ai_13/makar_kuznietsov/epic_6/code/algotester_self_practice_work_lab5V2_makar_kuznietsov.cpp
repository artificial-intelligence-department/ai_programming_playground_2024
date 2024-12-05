
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<string> cave(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> cave[i];
    }

    for (int col = 0; col < M; ++col)
    {
        int empty_row = N - 1;

        for (int row = N - 1; row >= 0; --row)
        {
            if (cave[row][col] == 'X')
            {

                empty_row = row - 1;
            }
            else if (cave[row][col] == 'S')
            {

                cave[row][col] = 'O';
                if (empty_row >= 0)
                {
                    cave[empty_row][col] = 'S';
                    empty_row--;
                }
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        cout << cave[i] << endl;
    }

    return 0;
}

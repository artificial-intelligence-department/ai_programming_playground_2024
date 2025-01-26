#include <iostream>
using namespace std;

int main()
{
    long long N;
    cin >> N;
    char array[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> array[i][j];
        }
    }
    cout << "C135" << " ";

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (array[i][j] == 'a')
            {
                for (int k = i + 1; k >= 0; k--)
                {
                    bool is_possible = true;
                    if (array[k][j] != 'A' && array[k][j] != '.' && array[k][j] != 'a')
                    {
                        is_possible = false;
                        break;
                    }
                    if (array[k][j] == 'A' && is_possible)
                    {
                        cout << j + 1 << " " << i + 1 << " " << j + 1 << " " << k + 1;
                        return 0;
                    }
                }
            }
            if (array[i][j] == 'A')
            {
                for (int k = i + 1; k >= 0; k++)
                {
                    bool is_possible = true;
                    if (array[k][j] != 'a' && array[k][j] != '.' && array[k][j] != 'A'){
                        is_possible = false;
                        break;
                    }
                    if (array[k][j] == 'a' && is_possible)
                    {
                        cout << j + 1 << " " << i + 1 << " " << j + 1 << " " << k + 1;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "none";
    return 0;
}

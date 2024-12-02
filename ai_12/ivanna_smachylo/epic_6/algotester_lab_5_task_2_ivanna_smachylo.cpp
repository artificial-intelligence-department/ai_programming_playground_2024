#include <iostream>
#include <cstring> 

using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;

int main() 
{
    int N, M;
    char cave[MAX_N][MAX_M + 1]; 

    cin >> N >> M;

    for (int i = 0; i < N; i++) 
    {
        cin >> cave[i];
    }

    for (int c = 0; c < M; c++) 
    {
        int empty_row = N - 1; 

        for (int r = N - 1; r >= 0; r--) 
        {
            if (cave[r][c] == 'X') 
            {
                empty_row = r - 1;
            } 
            else if (cave[r][c] == 'S') 
            {
                cave[r][c] = 'O'; 
                if (empty_row >= 0) 
                {
                    cave[empty_row][c] = 'S';
                    empty_row--; 
                }
            }
        }
    }
    cout << "\n";
    for (int i = 0; i < N; i++) 
    {
        cout << cave[i] << "\n";
    }

    return 0;
}
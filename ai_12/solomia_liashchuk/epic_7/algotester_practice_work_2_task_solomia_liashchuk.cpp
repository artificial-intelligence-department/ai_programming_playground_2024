#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> table(N, vector<int>(M));
    
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            cin >> table[i][j]; 

    int result = -1;
    
    for(int j = 0; j < M; ++j) 
    {
        int columnMax = table[0][j];
        for(int i = 1; i < N; ++i) 
        {
            columnMax = max(columnMax, table[i][j]);
        }
        
        result = (result == -1) ? columnMax : min(result, columnMax);
    }

    cout << result << endl;

    return 0;
}

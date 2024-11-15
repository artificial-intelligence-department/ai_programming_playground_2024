#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> table(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> table[i][j];
        }
    }
    
    int min_value = 2147483647;
    
    for (int j = 0; j < m; ++j) {
        int max_in_column = -2147483648;
        
        for (int i = 0; i < n; ++i) {
            max_in_column = max(max_in_column, table[i][j]);
        }
        
        min_value = min(min_value, max_in_column);
    }
    
    cout << min_value << endl;
    
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector <string> cave(n);
    for (int i = 0; i < n; i++) {
        cin>>cave[i];
    }
    int offset;
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < m; j++) {
                offset=0;
                while ( (i+offset<n) && (cave[i+offset][j] == 'O') && (cave[i - 1 + offset ][j] == 'S')) {
                    swap(cave[i+offset][j],cave[i-1+offset][j]);
                    offset++;
                }
            }
        }
    for (int i = 0; i < n; i++) {
        cout<<cave[i]<<endl;
    }
    return 0;
}






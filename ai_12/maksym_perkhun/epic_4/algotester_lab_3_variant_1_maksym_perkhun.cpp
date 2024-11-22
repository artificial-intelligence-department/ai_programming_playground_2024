#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin >> n;
    int set1[n];
    for (int i = 0; i < n; i++){
        cin >> set1[i];
    }
    cin >> m;
    int set2[m];
    for (int i = 0; i < m; i++){
        cin >> set2[i];
    }
    int u = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (set1[i] == set2[j]){
                u++;
                break;
            }
        }
    }
    cout << u << endl << n + m - u;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m, temp1, temp2 = 23131;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }    
    }
    for (int i = 0; i < m; i++){
        temp1 = arr[0][i];
        for (int j = 0; j < n; j++){
            if(arr[j][i] > temp1){
                temp1 = arr[j][i];
            }
        }
        if (temp2 > temp1){
            temp2 = temp1;
        }
    }
    cout << temp2;
    return 0;
}
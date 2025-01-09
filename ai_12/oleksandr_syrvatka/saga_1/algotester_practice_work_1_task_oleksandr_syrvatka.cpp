#include <bits/stdc++.h>
using namespace std;

//Перехід дороги 
int main() {
    int n, s = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++){
        if ((arr[i] % 2) != (arr[i+1] % 2)){
            s++;
        }
    }
    cout << s;
    return 0;
}
#include <iostream>

using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    int ar[n];
    for(int i = 0; i < n ; i++){
        cin >> ar[i];
    }

    for(int i = 0; i < n ; i++){
        for(int x = i + 1; x < n; x++ ){
            if (ar[x] < ar[i]){
                swap(ar[x], ar[i]);
            }
        }
    }
    
    int m = 0;
    for (int i = 0; i < n; i++){
        if(k >= ar[i]){
        k -= ar[i];
        m++;}
    }
    cout << m;
    return 0;
}
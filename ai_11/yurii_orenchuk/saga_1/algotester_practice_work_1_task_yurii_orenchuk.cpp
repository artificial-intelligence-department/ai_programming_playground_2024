#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//0365
int main(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ways = 1;

    for(int i = 1; i <= n; ++i){
        if(i < n && a[i - 1] < a[i]){
            ways++;
        }
    }

    cout << ways;

    return 0;
}

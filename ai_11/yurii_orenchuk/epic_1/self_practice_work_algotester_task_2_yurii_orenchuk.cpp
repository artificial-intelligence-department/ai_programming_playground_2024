#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, x;
    bool res = true;
    vector<int> dis;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        dis.push_back(x);
    }
    cout << '\n';

    for(int e = 1; e < n; ++e){
         if ((dis[e] - dis[e-1]) < 2) res = false;
    }

    if (res) cout << "YES";
    else cout << "NO";

    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n, x;
    cin >> n;
    vector<pair<int,int>> l;
    for(int i = 0; i<n ; i++){
        cin >> x;
        l.push_back({x, i});
    }
    sort(l.begin(), l.end());
    for(pair i:l){
        cout << i.second +1 << " ";
    }
    return 0;

}
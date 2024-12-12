#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int, int>> Length(n);
    for(int i=0; i<n; i++){
        cin>>Length[i].first;
        Length[i].second=i+1;
    }
    sort(Length.begin(), Length.end());
    for(int i=0; i<n; i++){
        cout<<Length[i].second<<" ";
    }
    return 0;
}
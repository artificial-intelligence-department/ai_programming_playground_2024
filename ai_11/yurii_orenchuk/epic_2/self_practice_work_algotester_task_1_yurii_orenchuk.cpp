#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> mar;
    vector<int> zen;
    int n, m, x;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> x;
        zen.push_back(x);
    }
    for(int i = 0; i < m; i++){
        cin >> x;
        mar.push_back(x);
    }

    auto min_zen = min_element(zen.begin(), zen.end());
    auto min_mar = min_element(mar.begin(), mar.end());
    int sum = *min_zen + *min_mar;

    cout << sum;

    return 0;
}
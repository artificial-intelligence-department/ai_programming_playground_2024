#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> office(n);
    
    for (int i = 0; i < n; ++i) {
        int li;
        cin >> li;
        office[i] = {li, i + 1};
    }
    
    sort(office.begin(), office.end());
    
    for (int i = 0; i < n; ++i) {
        cout << office[i].second;
        if (i < n - 1) {
            cout << " ";
        }
    }
    
    return 0;
}

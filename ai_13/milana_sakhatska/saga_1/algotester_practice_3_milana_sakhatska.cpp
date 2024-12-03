#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> lengths(n);
    for (int i = 0; i < n; ++i) {
        cin >> lengths[i];
    }
    vector<pair<int, int>> offices(n);
    for (int i = 0; i < n; ++i) {
        offices[i] = {lengths[i], i + 1}; 
    }

    sort(offices.begin(), offices.end());

    for (int i = 0; i < n; ++i) {
        cout << offices[i].second << " ";
    }
    cout << endl;

    return 0;
}

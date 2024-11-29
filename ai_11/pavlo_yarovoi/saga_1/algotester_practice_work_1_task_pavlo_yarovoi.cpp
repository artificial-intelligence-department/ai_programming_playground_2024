#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> lis;

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);
        if (it == lis.end()) {
            lis.push_back(a[i]);
        } else {
            *it = a[i];
        }
    }

    cout << lis.size() << endl;

    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<long long> h(4), d(4);
    long long minH = 1e13, maxH = -1;
    bool error = false, no = false;

    for (int i = 0; i < 4; i++) {
        cin >> h[i];
        maxH = max(maxH, h[i]);
        minH = min(minH, h[i]);
    }

    for (int i = 0; i < 4; i++) {
        cin >> d[i];
        if (d[i] > h[i]) {
            error = true;
        }
    }

    for (int i = 0; i < 4; i++) {
        h[i] -= d[i];
        maxH = *max_element(h.begin(), h.end());
        minH = *min_element(h.begin(), h.end());
        
        if (maxH >= 2 * minH) {
            no = true;
        }
    }

    if (error) {
        cout << "ERROR" << endl;
    } else {
        if (no || !(h[0] == h[1] && h[1] == h[2] && h[2] == h[3])) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}

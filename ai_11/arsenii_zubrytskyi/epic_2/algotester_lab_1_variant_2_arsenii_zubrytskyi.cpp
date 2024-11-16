#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long h1, h2, h3, h4;
    long long d1, d2, d3, d4;

    cin >> h1 >> h2 >> h3 >> h4;
    cin >> d1 >> d2 >> d3 >> d4;

    if (d1 > h1 || d2 > h2 || d3 > h3 || d4 > h4) {
        cout << "ERROR" << endl;
        return 0;
    }

    long long legs[4] = {h1, h2, h3, h4};
    long long cuts[4] = {d1, d2, d3, d4};

    for (int i = 0; i < 4; ++i) {
        legs[i] -= cuts[i];
        long long min_leg = *min_element(legs, legs + 4);
        long long max_leg = *max_element(legs, legs + 4);
        if (max_leg >= 2 * min_leg) {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (*min_element(legs, legs + 4) > 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

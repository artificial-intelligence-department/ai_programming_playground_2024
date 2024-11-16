//депутатські краватки

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

bool canCut(const vector<int>& ties, int m, double length) {
    int count = 0;
    for (double tie : ties) {
        count += static_cast<int>(tie / length);
        if (count >= m) {
            return true;
        }
    }
    return false;
}

double findMaxTieLength(const vector<int>& ties, int m) {
    double left = 0, right = *max_element(ties.begin(), ties.end());
    double precision = 1e-4;

    while (right - left > precision) {
        double mid = (left + right) / 2;
        if (canCut(ties, m, mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> ties(n);

    for (int i = 0; i < n; i++) {
        cin >> ties[i];
    }

    double result = findMaxTieLength(ties, m);
    cout << fixed << setprecision(6) << result << endl;

    return 0;
}

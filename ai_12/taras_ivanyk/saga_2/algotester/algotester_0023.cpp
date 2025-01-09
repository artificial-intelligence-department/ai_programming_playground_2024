#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

bool canCut(const vector<double>& tieLengths, double targetLength, int m) {
    int count = 0;
    for (double length : tieLengths) {
        count += static_cast<int>(length / targetLength);
        if (count >= m) {
            return true;
        }
    }
    return false;
}

double maxTieLength(int n, int m, const vector<double>& tieLengths) {
    double low = 0, high = *max_element(tieLengths.begin(), tieLengths.end());
    double bestLength = 0;

    while (high - low > 1e-5) { 
        double mid = (low + high) / 2;
        if (canCut(tieLengths, mid, m)) {
            bestLength = mid;
            low = mid;
        } else {
            high = mid;
        }
    }

    return bestLength;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<double> tieLengths(n);
    for (int i = 0; i < n; ++i) {
        cin >> tieLengths[i];
    }
    double result = maxTieLength(n, m, tieLengths);

    cout << fixed << setprecision(6) << result << endl;

    return 0;
}

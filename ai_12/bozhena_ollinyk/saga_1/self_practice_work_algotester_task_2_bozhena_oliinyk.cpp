#include <iostream>
#include <iomanip>

using namespace std;

// 0023
//Депутатські краватки

int main() {
    int n, m;
    cin >> n >> m;

    int krav[n];
    int totalLength = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        cin >> krav[i];
        totalLength += krav[i];
        if (krav[i] > maxLength) {
            maxLength = krav[i];
        }
    }

    double left = 0.0, right = maxLength;
    double result = 0.0;

    while (right - left > 1e-7) {
        double mid = (left + right) / 2.0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            count += static_cast<int>(krav[i] / mid); 
        }

        if (count >= m) {
            result = mid;
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << fixed << setprecision(7) << result << endl;

    return 0;
}

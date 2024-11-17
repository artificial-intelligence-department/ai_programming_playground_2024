#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int ties[1000];
    for (int i = 0; i < n; i++) {
        cin >> ties[i];
    }

    double low = 0.0, high = 1e9, mid;
    double result = 0.0;

    while (high - low > 1e-6) { 
        mid = (low + high) / 2.0;

        int count = 0;

        for (int i = 0; i < n; i++) {
            count += ties[i] / mid;
        }

        if (count >= m) {
            result = mid;
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << fixed << setprecision(7) << result << endl;
    return 0;
}

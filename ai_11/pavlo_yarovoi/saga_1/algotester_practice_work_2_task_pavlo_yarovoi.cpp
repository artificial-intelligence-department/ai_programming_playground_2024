#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 1 || n > 1000) {
        return 1;
    }

    int votes[n];

    for (int i = 0; i < n; i++) {
        cin >> votes[i];

        if (votes[i] < 1 || votes[i] > 1000000000) {
            return 1;
        }
    }

    int gcd_val = votes[0];

    for (int i = 1; i < n; i++) {
        int a = gcd_val, b = votes[i];
        while (b != 0) {
            a %= b;
            swap(a, b);
        }
        gcd_val = a;
    }

    long long total_seats = 0;

    for (int i = 0; i < n; i++) {
        total_seats += static_cast<long long>(votes[i]) / gcd_val;
    }

    cout << total_seats << endl;

    return 0;
}


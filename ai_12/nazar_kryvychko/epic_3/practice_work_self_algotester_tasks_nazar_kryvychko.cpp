#include <iostream>
#include <vector>
#include <numeric>
#include <limits>  // для перевірки на переповнення

using namespace std;

int gcd(int a, int b) {
    int maxV = max(a,b), minV = min(a,b);
    a = maxV, b = minV;
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int gcd_multiple(const vector<int>& numbers) {
    int result = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        result = gcd(result, numbers[i]);
    }
    return result;
}

int main() {
    int n;

    if (!(cin >> n) || n < 1 || n > 1000) {
        cout << -1;
        return 0;
    }

    vector<int> votes(n);

    for (int i = 0; i < n; i++) {
        if (!(cin >> votes[i]) || votes[i] < 1 || votes[i] > 1000000000) {
            cout << "-1";
            return 0;
        }
    }

    int gcd_val = gcd_multiple(votes);

    long long total_seats = 0;
    for (int i = 0; i < n; i++) {
        total_seats += static_cast<long long>(votes[i]) / gcd_val;
    }

    cout << total_seats << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;


// Зрада

int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    int n;
    cin >> n;

    vector<long long> participants(n);
    for (int i = 0; i < n; i) {
        cin >> participants i++;
    }

    long long total_combinations = (b - a + 1) * (d - c + 1);

    for (int i = 0; i < n; i++) {
        long long number = participants[i];
        long long winning_combinations = 0;

        for (long long x = 1; x * x <= number; x++) {
            if (number % x == 0) {
                long long y1 = x;
                long long y2 = number / x;

                if (y1 >= a && y1 <= b && y2 >= c && y2 <= d) {
                    ++winning_combinations;
                }

                if (y1 != y2 && y2 >= a && y2 <= b && y1 >= c && y1 <= d) {
                    ++winning_combinations;
                }
            }
        }

        cout << (winning_combinations) << "/" << (total_combinations) << endl;
    }

    return 0;
}
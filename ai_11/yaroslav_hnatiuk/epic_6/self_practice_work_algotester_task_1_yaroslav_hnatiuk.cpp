#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long calculation(long long a, long long b) {
    if (b == 0) return a;
    else return calculation(b, a % b);
}

int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    
    long long totalCombo = (b - a + 1) * (d - c + 1);

    int n;
    cin >> n;

    vector<long long> participants(n);
    for (int i = 0; i < n; i++) cin >> participants[i];

    for (int i = 0; i < n; i++) {
        long long number = participants[i];
        long long winСombo = 0;

        for (long long j = 1; j * j <= number; j++) {
            if (number % j == 0) {
                long long x1 = j;
                long long x2 = number / j;

                if (x1 >= a && x1 <= b && x2 >= c && x2 <= d) winСombo++;
                if (x1 != x2 && x2 >= a && x2 <= b && x1 >= c && x1 <= d) winСombo++;
            }
        }

        long long divisor = calculation(winСombo, totalCombo);
        cout << (winСombo / divisor) << "/" << (totalCombo / divisor) << endl;
    }

    return 0;
}

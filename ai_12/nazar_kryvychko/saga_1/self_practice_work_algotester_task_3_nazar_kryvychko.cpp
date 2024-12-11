#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (n == 0 || k == 0) {
        cout << fixed << setprecision(6) << 0.0 << endl;
    } else {
        double probability = 1.0 / (n * k);
        cout << fixed << setprecision(6) << probability << endl;
    }

    return 0;
}

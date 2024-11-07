#include <iostream>
using namespace std;

int main() {
    long long a[5];

    for (int i = 0; i < 5; ++i) {
        cin >> a[i];

        if (a[i] <= 0) {
            cout << "ERROR" << endl;
            return 0;
        }
    }

    for (int i = 1; i < 5; ++i) {
        if (a[i] > a[i - 1]) {
            cout << "LOSS" << endl;
            return 0;
        }
    }

    cout << "WIN" << endl;
    return 0;
}

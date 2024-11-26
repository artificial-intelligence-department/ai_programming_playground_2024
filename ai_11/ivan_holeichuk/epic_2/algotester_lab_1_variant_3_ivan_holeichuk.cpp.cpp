#include <iostream>
using namespace std;

int main() {

    long long a[5];
    cin >> a[0];

    if (a[0] <= 0 || a[0] > 1e12) {
        cout << "error";

        return 0;
    }

    for (int i = 1; i < 5; i++) {
        cin >> a[i];

        if (a[i] <= 0 || a[i] > 1e12) {
            cout << "error" << endl;

            return 0;
        }
        else if (a[i] > a[i - 1]) {
            cout << "loss" << endl;

            return 0;
        }
    }

    cout << "win" << endl;

    return 0;
}
    
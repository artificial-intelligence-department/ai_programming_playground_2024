#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long l, w, u, d;
    cin >> l >> w >> u >> d;

    if (l <= w && l <= (u + d)) {
        cout << "Three times Sex on the Beach, please!" << endl;
    } else {
        cout << "Forget about the cocktails, man!" << endl;
    }

    return 0;
}






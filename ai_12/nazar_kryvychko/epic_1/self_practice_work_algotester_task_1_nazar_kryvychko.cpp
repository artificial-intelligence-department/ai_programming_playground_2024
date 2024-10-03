#include <iostream>
using namespace std;

int main() {
    int l, w, u, d;
    cin >> l >> w >> u >> d;

    if (w >= l && (u + d) >= l) {
        cout << "Three times Sex on the Beach, please!" << endl;
    } else {
        cout << "Forget about the cocktails, man!" << endl;
    }
    return 0;
}

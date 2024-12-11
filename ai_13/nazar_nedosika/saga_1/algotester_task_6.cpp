#include <iostream>
using namespace std;

int main() {
    int l, w, u, d;
    cin >> l >> w >> u >> d;

    if (l <= w && l <= u + d) cout << "Three times Sex on the Beach, please!";
    else cout << "Forget about the cocktails, man!";

    return 0;
}
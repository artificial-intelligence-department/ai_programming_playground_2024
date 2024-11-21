#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long l, w, u, d;
    cin >> l >> w >> u >> d;

    // якщо д≥аметр коктейлю менший або р≥вний ширин≥ рота та висот≥ рота, п≥нгв≥н може випити коктейль
    if (l <= w && l <= u + d) {
        cout << "Three times Sex on the Beach, please!" << endl;
    }
    else {
        cout << "Forget about the cocktails, man!" << endl;
    }

    return 0;
}

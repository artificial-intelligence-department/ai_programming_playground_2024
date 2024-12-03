#include <iostream>
using namespace std;

int main() {
    int L, W, U, D;
    cin >> L >> W >> U >> D;

    if (W >= L && U + D >= L) {
        cout << "Three times Sex on the Beach, please!" << endl;
    } else {
        cout << "Forget about the cocktails, man!" << endl;
    }

    return 0;
}

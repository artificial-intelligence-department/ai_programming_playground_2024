#include <iostream>
using namespace std;

int main() {
    long long cubes[5];

    for (int i = 0; i < 5; i++) {
        cin >> cubes[i];
    }

    for (int i = 1; i < 5; i++) {
        if (cubes[i] <= 0) {
            cout << "ERROR" << endl;
            return 0;
        }
        if (cubes[i] > cubes[i - 1]) {
            cout << "LOSS" << endl;
            return 0;
        }
    }

    cout << "WIN" << endl;
    return 0;
}

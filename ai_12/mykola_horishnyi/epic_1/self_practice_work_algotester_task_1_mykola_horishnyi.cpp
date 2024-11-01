#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long R, r;
    cin >> R >> r;


    if (R * (sqrt(3) - 1) >= r) {
        cout << "safe" << endl;
    } else {
        cout << "rumpled" << endl;
    }

    return 0;
}
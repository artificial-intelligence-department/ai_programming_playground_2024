#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int INum;
    cin >> INum;
    int Arr[16] = {};
    for (int i = 0; i < 16; i++) {
        // cout << INum << endl;
        if (INum == 1) {
            Arr[i] = 1;
            INum /= 2;
        } else {
            Arr[i] = INum % 2;
            INum /= 2;
        }
        // cout << Arr[i];
    }
    int size = sizeof(Arr) / sizeof(Arr[0]);
    reverse(Arr, Arr + size);
    for (int i = 0; i < 16; i++) {
        cout << Arr[i];
    }

    return 0;
}
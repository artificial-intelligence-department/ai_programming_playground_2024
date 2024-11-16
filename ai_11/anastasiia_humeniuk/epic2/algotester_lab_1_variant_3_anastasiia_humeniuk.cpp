#include <iostream>
using namespace std;

int main() {
    long long cubes[5];
    const long long MAX_VALUE = 1000000000000; 

    for (int i = 0; i < 5; ++i) {
        cin >> cubes[i];


        if (cubes[i] <= 0 || cubes[i] > MAX_VALUE) {
            cout << "ERROR" << endl;
            return 0;
        }


        if (i > 0 && cubes[i] > cubes[i - 1]) {
            cout << "LOSS" << endl;
            return 0;
        }
    }

    cout << "WIN" << endl;
    return 0;
}

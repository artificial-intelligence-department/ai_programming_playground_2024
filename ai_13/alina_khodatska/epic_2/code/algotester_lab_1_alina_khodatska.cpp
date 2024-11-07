#include <iostream>
using namespace std;

int main() {
    long long prev_cube, current_cube;
    cin >> prev_cube;

    if (prev_cube <= 0) {
        cout << "ERROR" << endl;
        return 0;
    }

    for (int i = 1; i < 5; ++i) {
        cin >> current_cube;

        if (current_cube <= 0) {
            cout << "ERROR" << endl;
            return 0;
        }

        if (current_cube > prev_cube) {
            cout << "LOSS" << endl;
            return 0;
        }

        prev_cube = current_cube; 
    }

    cout << "WIN" << endl;
    return 0;
}

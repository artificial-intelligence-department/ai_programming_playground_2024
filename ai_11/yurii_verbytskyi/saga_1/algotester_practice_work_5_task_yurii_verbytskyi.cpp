#include <iostream>

using namespace std;

int main() {
    unsigned long long h[4];
    for (int i = 0; i < 4; i++) {
        cin >> h[i];
    }

    unsigned long long d[4];
    for (int i = 0; i < 4; i++) {
        cin >> d[i];
    }

    unsigned long long max = h[0];
    bool turn_over = false;
    for (int i = 0; i < 4; i++) {
        if (d[i] > h[i]) {
            cout << "ERROR";
            return 0;
        }

        if (h[i] - d[i] == 0) {
            turn_over = true;
        }

        h[i] -= d[i];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (h[i] >= 2 * h[j]) {
                    turn_over = true;
                    break;
                }
            }
            if (turn_over) {
                break;
            }
        }
    }

    unsigned long long min = h[0];

    for (int i = 0; i < 4; i++) {
        if (h[i] < min) {
            min = h[i];
        }
        if (h[i] > max) {
            max = h[i];
        }
    }

    if(turn_over == true){
        cout << "NO";
    } else cout << "YES";
    return 0;
}

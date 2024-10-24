#include <iostream>
using namespace std;


int main() {
    long long d_legs[4], d_saw[4];

    for (int i = 0; i < 4; i++) cin >> d_legs[i];

    bool is_error = false;
    for (int i = 0; i < 4; i++) {
        cin >> d_saw[i];

        if (d_legs[i] < d_saw[i])
            is_error = true;
    }   


    if (!is_error) {
        bool y_or_n = true;
        for (int i = 0; i < 4; i++) {
            d_legs[i] -= d_saw[i];

            long long d_max = d_legs[0], d_min = d_legs[0];
            for (int j = 1; j < 4; j++) {
                if (d_legs[j] < d_min) d_min = d_legs[j];
                if (d_legs[j] > d_max) d_max = d_legs[j];
            }

            if (d_max >= 2 * d_min) {
                y_or_n = false;
                break;
            }
        }

        if (y_or_n) cout << "YES";
        else cout << "NO";
    } else cout << "ERROR";

    return 0;
}


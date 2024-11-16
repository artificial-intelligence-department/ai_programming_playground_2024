#include <iostream>
using namespace std;


int main() {
    long long Hleg[4], Cleg[4];

    for (int i = 0; i < 4; i++) cin >> Hleg[i];

    bool answer = false;
    for (int i = 0; i < 4; i++) {
        cin >> Cleg[i];

        if (Hleg[i] < Cleg[i])
            answer = true;
    }   


    if (!answer) {
        bool answer2 = true;
        for (int i = 0; i < 4; i++) {
            Hleg[i] -= Cleg[i];

            long long H_max = Hleg[0], H_min = Hleg[0];
            for (int i = 1; i < 4; i++) {
                if (Hleg[i] < H_min) H_min = Hleg[i];
                if (Hleg[i] > H_max) H_max = Hleg[i];
            }

            if (H_max >= 2 * H_min) {
                answer2 = false;
                break;
            }
        }

        if (answer2) cout << "YES";
        else cout << "NO";
    } else cout << "ERROR";

    return 0;
}

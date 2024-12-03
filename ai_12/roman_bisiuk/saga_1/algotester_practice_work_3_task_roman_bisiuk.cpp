#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    string results;
    cin >> results;

    int kolyaPoints = 0, vasyaPoints = 0;
    int kolyaWins = 0, vasyaWins = 0;

    for (char c : results) {
        if (c == 'K') {
            kolyaPoints++;
        } else if (c == 'V') {
            vasyaPoints++;
        }

        if ((kolyaPoints >= 11 || vasyaPoints >= 11) && abs(kolyaPoints - vasyaPoints) >= 2) {
            if (kolyaPoints > vasyaPoints) {
                kolyaWins++;
            } else {
                vasyaWins++;
            }
            kolyaPoints = 0;
            vasyaPoints = 0;
        }
    }

    cout << kolyaWins << ":" << vasyaWins << endl;

    if (kolyaPoints > 0 || vasyaPoints > 0) {
        cout << kolyaPoints << ":" << vasyaPoints << endl;
    }

    return 0;
}

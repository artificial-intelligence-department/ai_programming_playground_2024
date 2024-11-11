#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    string results;
    cin >> results;

    int kolyaWins = 0, vasyaWins = 0;
    int kolyaScore = 0, vasyaScore = 0;

    for (int i = 0; i < n; ++i) {
        if (results[i] == 'K') {
            kolyaScore++;
        } else if (results[i] == 'V') {
            vasyaScore++;
        }

        if ((kolyaScore >= 11 || vasyaScore >= 11) && (kolyaScore - vasyaScore) >= 2) {
            if (kolyaScore > vasyaScore) {
                kolyaWins++;
            }
            else {
                vasyaWins++;
            }

            kolyaScore = 0;
            vasyaScore = 0;
        }
    }

    cout << kolyaWins << ":" << vasyaWins << endl;

    if (kolyaScore > 0 || vasyaScore > 0) {
        cout << kolyaScore << ":" << vasyaScore << endl;
    }

    return 0;
}
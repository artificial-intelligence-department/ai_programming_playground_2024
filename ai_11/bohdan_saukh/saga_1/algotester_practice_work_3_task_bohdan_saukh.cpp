#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string game;
    cin >> game;

    int kolyaGames = 0, vasyaGames = 0;
    int kolyaPoints = 0, vasyaPoints = 0;

    for (int i = 0; i < n; i++) {
        if (game[i] == 'K') {
            kolyaPoints++;
        } else if (game[i] == 'V') {
            vasyaPoints++;
        }

        if (kolyaPoints >= 11 && kolyaPoints - vasyaPoints >= 2) {
            kolyaGames++;
            kolyaPoints = 0;
            vasyaPoints = 0;
        } else if (vasyaPoints >= 11 && vasyaPoints - kolyaPoints >= 2) {
            vasyaGames++;
            kolyaPoints = 0;
            vasyaPoints = 0;
        }
    }

    cout << kolyaGames << ":" << vasyaGames << endl;

    if (kolyaPoints > 0 || vasyaPoints > 0) {
        cout << kolyaPoints << ":" << vasyaPoints << endl;
    }

    return 0;
}


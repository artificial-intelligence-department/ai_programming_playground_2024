#include <iostream>
using namespace std;

int main() {
    long long health, mana;
    cin >> health >> mana;

    long long hpCost[3], manaCost[3];

    for (int i = 0; i < 3; ++i) {
        cin >> hpCost[i] >> manaCost[i];

        if (hpCost[i] > 0 && manaCost[i] > 0) {
            cout << "NO" << endl;
            return 0;
        }
        health -= hpCost[i];
        mana -= manaCost[i];

        if (health <= 0 || mana <= 0) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}

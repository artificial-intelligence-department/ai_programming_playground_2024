#include <iostream>
using namespace std;

int main() {

    long long Hitpoints, Mana;
    long long HitpointsLoss, ManaLoss;
    cin >> Hitpoints >> Mana;
    for(short int rows = 0; rows < 3; rows++) {
            cin >> HitpointsLoss >> ManaLoss;
            if(HitpointsLoss > 0 && ManaLoss > 0) {
                cout << "NO";
                return 0;
            } else {
                Hitpoints -= HitpointsLoss;
                Mana -= ManaLoss;
            }
        }
    if(Hitpoints > 0 && Mana > 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
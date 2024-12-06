#include <iostream>
using namespace std;

int main() {
    long long health, magic;
    cin >> health >> magic;

    bool isValid = true;
    for (int attempt = 0; attempt < 3; ++attempt) {
        long long damage, manaCost;
        cin >> damage >> manaCost;

        if (damage > 0 && manaCost > 0) {
            isValid = false;
            break;
        }
 
        health -= damage;
        magic -= manaCost;
    }

    if (health > 0 && magic > 0 && isValid)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
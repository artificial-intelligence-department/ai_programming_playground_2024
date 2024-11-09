#include <iostream>
using namespace std;

bool canPenguinDrinkCocktail(int l, int w, int u, int d) {
    int maxHeight = u + d;
    return (w >= l) && (maxHeight >= l);
}

int main() {
    int l, w, u, d;
    cin >> l >> w >> u >> d; 

    if (canPenguinDrinkCocktail(l, w, u, d) == true ) {
        cout << "Three times Sex on the Beach, please!" << endl;
    } else {
        cout << "Forget about the cocktails, man!" << endl;
    }
    return 0;
}
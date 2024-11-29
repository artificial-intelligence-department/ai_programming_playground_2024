#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if ((n * m) % 2 == 0) {
        cout << "Dragon" << endl;
    } else {
        cout << "Imp" << endl;
    }

    return 0;
}
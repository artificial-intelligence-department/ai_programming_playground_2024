// Algotester [Interesting Game] 0181
#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    if ((N * M) % 2 == 0) {
        cout << "Dragon" << endl; 
    } else {
        cout << "Imp" << endl;
    }

    return 0;
}

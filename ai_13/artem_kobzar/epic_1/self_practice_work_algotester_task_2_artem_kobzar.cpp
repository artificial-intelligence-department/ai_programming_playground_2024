#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if ((n * m) % 2 == 1) {
        cout << "Imp";
    } else {
        cout << "Dragon";
    }
 return 0;
}

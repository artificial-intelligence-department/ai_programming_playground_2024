#include <iostream>
using namespace std;

int main() {
    int n, m;

    cin >> n;
    cin >> m;

    cout << endl << n++ - m << endl;
    cout << bool (m-- > n) << endl;
    cout << bool (n-- > m);

    return 0;
}


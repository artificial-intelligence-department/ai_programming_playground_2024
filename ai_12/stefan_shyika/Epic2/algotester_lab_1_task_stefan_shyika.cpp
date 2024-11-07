#include <iostream>
using namespace std;

int main() {
    long long H, M;
    cin >> H >> M;

    long long h1, m1, h2, m2, h3, m3;
    cin >> h1 >> m1;
    cin >> h2 >> m2;
    cin >> h3 >> m3;

    if ((h1 > 0 && m1 > 0) || (h2 > 0 && m2 > 0) || (h3 > 0 && m3 > 0)) {
        cout << "NO" << endl;
        return 0;
    }

    long long Hfinal = H - (h1 + h2 + h3);
    long long Mfinal = M - (m1 + m2 + m3);

    if (Hfinal > 0 && Mfinal > 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

#include <iostream>
using namespace std;

int main() {
    long long H, M, h1, m1, h2, m2, h3, m3;
    const long long limit = 1000000000000;
    cin >> H >> M >> h1 >> m1 >> h2 >> m2 >> h3 >> m3;

    if (H >= 1 && H <= limit && M >= 1 && M <= limit &&
        h1 >= 0 && h1 <= limit && m1 >= 0 && m1 <= limit &&
        h2 >= 0 && h2 <= limit && m2 >= 0 && m2 <= limit &&
        h3 >= 0 && h3 <= limit && m3 >= 0 && m3 <= limit) {
        
        if ((h1 == 0 || m1 == 0) && (h2 == 0 || m2 == 0) && (h3 == 0 || m3 == 0)) {
            H -= (h1 + h2 + h3);
            M -= (m1 + m2 + m3);
            if (H > 0 && M > 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            
        } else {
            cout << "NO" << endl;
        }
        
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

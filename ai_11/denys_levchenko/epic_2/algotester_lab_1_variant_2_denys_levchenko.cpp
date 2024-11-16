#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long h[4]; // ножки
    long long d[4]; // довжина обрізання ніжок
    for (int i = 0; i < 4; ++i) {
        cin >> h[i];
    }
    for (int i = 0; i < 4; ++i) {
        cin >> d[i];
    }
    for (int i = 0; i < 4; ++i) {
        if (d[i] > h[i]) {
            cout << "ERROR" << endl;
            return 0;
        }
    }

    // Перевірка на перевертання
    for (int i = 0; i < 4; ++i) {
        h[i] -= d[i];
        long long hmin = *min_element(h, h + 4);
        long long hmax = *max_element(h, h + 4);
        if (hmax >= 2 * hmin) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}

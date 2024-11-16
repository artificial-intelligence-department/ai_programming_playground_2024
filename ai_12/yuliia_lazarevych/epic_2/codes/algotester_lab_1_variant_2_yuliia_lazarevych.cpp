#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long h[4], d[4];
    cin >> h[0] >> h[1] >> h[2] >> h[3] >> d[0] >> d[1] >> d[2] >> d[3];

    // перевіряємо аби довжина відпилення була меншою за початкову довжину ніжки
    for (int i = 0; i < 4; ++i) {
        if (d[i] > h[i]) {
            cout << "ERROR" << endl;
            return 0;
        }
    }

    //присвоюємо ніжкам оновленні значення, шукаємо мінімальну та максимальну ніжку і перевіряємо стіл на стійкість
    for (int i = 0; i < 4; ++i) {
        h[i] -= d[i];

        long long hmin = *min_element(h, h + 4);
        long long hmax = *max_element(h, h + 4);

        if (hmax >= 2 * hmin || hmin == 0) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl; //якщо в результаті зі столом все добре і він стоїть
    return 0;
}

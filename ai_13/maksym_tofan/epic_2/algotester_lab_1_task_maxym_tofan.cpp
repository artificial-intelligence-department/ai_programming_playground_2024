
#include <iostream>
using namespace std;

int main() {
    // Вхідні дані: початкові хітпойнти та мана персонажа
    long long H, M;
    cin >> H >> M;

    bool valid = true;  // Перевірка на правильність використання заклинань
    for (int i = 0; i < 3; ++i) {
        long long hi, mi;
        cin >> hi >> mi;

        // Якщо закляття використовує і хітпойнти, і ману одночасно
        if (hi > 0 && mi > 0) {
            valid = false;
        }

        // Зменшуємо відповідно хітпойнти або ману
        H -= hi;
        M -= mi;
    }

    // Перевіряємо умови виграшу
    if (valid && H > 0 && M > 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}


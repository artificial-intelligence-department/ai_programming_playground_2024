#include <iostream>
using namespace std;

int main() {
    long long l, w, u, d;  // Довжина, ширина, висота рота, діаметр коктейлю
    cin >> l >> w >> u >> d;

    // Якщо діаметр коктейлю менший або рівний ширині та висоті рота, пінгвін може випити коктейль
    if (l <= w && l <= u + d) {
        cout << "Three times Sex on the Beach, please!" << endl;
    }
    else {
        cout << "Forget about the cocktails, man!" << endl;
    }

    return 0;  // повернення 0 (вказує на успішне завершення програми)
}

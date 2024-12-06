#include <iostream>
using namespace std;

int main() {
    uint64_t a; //поточний стан дошки
    int N; //к-ть заклинань
    cin >> a >> N;

    for (int i = 0; i < N; i++) {
        int R, C;
        cin >> R >> C;
        R--; C--; //переходимо до 0-індексації

        //інвертуємо рядок R
        for (int j = 0; j < 8; j++) {
            a ^= (1ULL << (R * 8 + j));
        }

        //інвертуємо стовпець C
        for (int j = 0; j < 8; j++) {
            if (j != R) { //уникаємо подвійної інверсії
                a ^= (1ULL << (j * 8 + C));
            }
        }
    }

    cout << a << endl; //виводимо кінцевий стан
    return 0;
}

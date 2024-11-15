#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Визначаємо змінні для обчислень у float і double
    float af = 1000, bf = 0.0001;

    // Обчислення виразу з точністю float
    float step1_f = pow(af - bf, 2);
    float step2_f = af * af - 2 * af * bf;
    float step3_f = pow(bf, 2);
    float result_f = (step1_f - step2_f) / step3_f;

    double ad = 1000, bd = 0.0001;

    double step1_d = pow(ad - bd, 2);
    double step2_d = ad * ad - 2 * ad * bd;
    double step3_d = pow(bd, 2);
    double result_d = (step1_d - step2_d) / step3_d;

    // Виведення результатів
    cout << "Результат через float: " << result_f << endl;
    cout << "Результат череp double: " << result_d << endl;

    return 0;
}


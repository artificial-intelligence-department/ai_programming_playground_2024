#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    // Обчислюємо радіус найменшого ярусу
    double r_min = sqrt(static_cast<double>(r * r) / n);

    // Виводимо результат з точністю 4 знаки після коми
    cout << fixed << setprecision(4) << r_min << endl;

    return 0;
}

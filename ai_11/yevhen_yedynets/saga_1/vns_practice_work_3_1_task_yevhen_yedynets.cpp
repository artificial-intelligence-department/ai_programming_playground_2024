#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a, b, c, d;

    cout << "Введіть значення a, b, c, d через пробіл: ";
    cin >> a >> b >> c >> d;

    double multiplication_ab = a * b;
    double multiplication_cd = c * d;
    double difference = multiplication_ab - multiplication_cd;

    cout << fixed << setprecision(7);
    cout << "Різниця (" << a << " * " << b << ") - (" << c << " * " << d << ") = " << difference << endl;

    return 0;
}

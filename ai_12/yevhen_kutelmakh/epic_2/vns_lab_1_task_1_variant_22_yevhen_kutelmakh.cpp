//((a - b)^4 - (a^4 - 4a^3 * b)) / (6*(ab)^2 - 4a * b^3 + b^4), a = 100, b = 0.001
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    {
    float a = 100;
    float b = 0.001;
    float exp1 = pow(a-b, 4);
    float exp2 = pow(a, 4);
    float exp3 = pow(a, 3) * 4 * b;
    float exp4 = pow(a*b, 2) * 6;
    float exp5 = pow(b, 3) * 4 * a;
    float exp6 = pow(b, 4);
    float exp7 = exp1 - exp2 + exp3;
    float exp8 = exp4 - exp5 + exp6;
    float res = exp7 / exp8;
    cout << "float: \t\t" << res << "\n";
    }
    cout << "--------------------------\n";
    {
    double a = 100;
    double b = 0.001;
    double exp1 = pow(a-b, 4);
    double exp2 = pow(a, 4);
    double exp3 = pow(a, 3) * 4 * b;
    double exp4 = pow(a*b, 2) * 6;
    double exp5 = pow(b, 3) * 4 * a;
    double exp6 = pow(b, 4);
    double exp7 = exp1 - exp2 + exp3;
    double exp8 = exp4 - exp5 + exp6;
    double res = exp7 / exp8;
    cout << "double: \t" << res << "\n";
    }
    /*
    Результати різні, і різниця доволі суттєва, а сталось так,
    тому що тип double може приймати більший діапазон значень
    ніж тип float, тому на певній стадії обчислень відбулось переповнення
    і записалось неправильне значення в тип float, що і призвело до результату
    */
    return 0;
}
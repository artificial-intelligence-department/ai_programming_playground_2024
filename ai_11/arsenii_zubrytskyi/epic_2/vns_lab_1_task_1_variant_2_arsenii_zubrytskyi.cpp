#include <iostream>
#include <cmath>
#include <iomanip>  // Для setprecision

using namespace std;

int main() {
    // Для double
    double a = 1000.0, b = 0.0001;
    double numerator_d, denominator_d, result1;

    // Обчислення для double
    numerator_d = pow((a - b), 2) - (pow(a, 2) - 2 * a * b);  // (a-b)^2 - (a^2 - 2ab)
    denominator_d = pow(b, 2); // b^2

    result1 = numerator_d / denominator_d;
    cout << setprecision(10) << "Result for double: " << result1 << endl;

    // Для float
    float a1 = 1000.0f, b1 = 0.0001f, num1 = 0, num2 = 0, num3 = 100;
    float numerator_f, denominator_f, result2;

    // Обчислення для float
    num1 = pow(a1 - b1, 2) ;
    num2 = pow(a1, 2);
    // num3 = (2*a1)*b1;
    numerator_f = num1 - (num2 - num3);  // (a-b)^2 - (a^2 - 2ab)
    denominator_f = pow(0.0001 , 2);

    result2 = numerator_f / denominator_f;

    // Округлення результатів для float для виведення
    cout << "Result for float: " << result2 << endl;

    return 0;
}

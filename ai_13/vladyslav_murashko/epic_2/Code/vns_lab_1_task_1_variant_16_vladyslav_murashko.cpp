#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // константи задані умовою задачі
    const int a = 1000;
    const float b = 0.0001;

    // створюємо декілька проміжних змінних
    const double n1 = pow(a - (double)b, 3);
    const double n2 = 3 * pow(a, 2) * b;
    const double n3 = pow(a, 3) - n2;

    const double d1 = pow(b, 3);
    const double d2 = 3 * a * pow(b, 2);

    const double numerator = n1 - n3;
    const double denumenator = d1 - d2;

    const double result = numerator / denumenator;

    cout << "\nThe final answer is " << result << "\n\n";
    return 0;
}
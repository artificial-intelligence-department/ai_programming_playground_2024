#include <iostream>
#include <cmath> 

int main() {
    double P, r, n, t;

    printf("Введіть вкладену суму: ");
    scanf("%lf", &P);
    printf("Введіть річну процентну ставку десятковим числом (наприклад, 0.05 для 5%): ");
    scanf("%lf", &r);
    printf("Введіть кількість нарахувань відсотків на рік: ");
    scanf("%lf", &n);
    printf("Введіть кількість років, на які інвестуються гроші: ");
    scanf("%lf", &t);

    double A = P * pow((1 + (r / n)), (n * t));

    printf("Вкладена сума: %.2lf\n", P);
    printf("Сума заробітку: %.2lf\n", A);

    return 0;
}

#include <iostream>
#include <cmath>
#include <cstdio>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "ukr");

    double P, r, A;
    int n, t;

    printf("Введіть початкову суму інвестицій (P): ");
    scanf("%lf", &P);

    printf("Введіть річну процентну ставку : ");
    scanf("%lf", &r);

    printf("Введіть кількість нарахувань відсотків на рік (n): ");
    scanf("%d", &n);

    printf("Введіть тривалість інвестицій у роках (t): ");
    scanf("%d", &t);

    r = r / 100;
    A = P * pow(1 + r / n, n * t);

    printf("\nПочаткова сума: %.2f\n", P);
    printf("Загальна сума інвестицій після %d років: %.2f\n", t, A);
    printf("Зароблена сума: %.2f\n", A - P);

    return 0;
}

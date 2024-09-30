#include <stdio.h>
#include <cmath>

int main(){
    double A, P, r, n, t;
    printf("Введіть суму вашої інвестиції: ");
    scanf("%lf", &P);

    printf("Введіть річну процентну ставку: ");
    scanf("%lf", &r);

    printf("Введіть кількість нарахувань відсотків на рік: ");
    scanf("%lf", &n);

    printf("Введіть час, на який інвестуються гроші у роках: ");
    scanf("%lf", &t);

    A = P * pow(1 + (r / n), n * t);
    printf("Вкладені гроші: %.2lf\n", P);
    printf("Майбутня загальна сума інвестиції: %.2lf\n", A);
    printf("Сума заробітку: %.2lf\n", A - P);

    return 0;
}
#include <stdio.h>
#include <math.h>

int main() {
    double P, r;
    printf ("Введіть суму інвестицій: ");
    scanf ("%lf", &P);

    printf ("Введіть річну процентну ставку: ");
    scanf ("%lf" , &r);
    r = r / 100;

    float t;
    printf ("Введіть час інвестиції (в роках): ");
    scanf ("%f", &t);

    int n;
    printf ("Оберіть кількість нарахувань відсотків на рік (1-щороку, 4-кожен квартал, 12-кожного місяця): ");
    scanf ("%d", &n);

    double A, np; // np- net profi чистий прибуток
    A = P * pow((1 + r / n), n * t);
    np = A - P;

    printf ("Сума інвестицій: %.2lf\n", P);
    printf ("Фінальна сума інвестицій: %.2lf\n", A);
    printf ("Сума зароблених відсотків: %.2lf\n", np);

    return 0;
}

#include <stdio.h>
#include <cmath>

int main () {
    double A, P, r, n, t;

    printf ("Введіть основну суму інвестиції: ");
    scanf ("%lf", &P);

    printf ("Введіть річну відсоткову ставку: ");
    scanf ("%lf", &r);

    printf ("Введіть кількість нарахувань відсотків за рік: ");
    scanf ("%lf", &n);

    printf ("Введіть термін інвестиції у роках: ");
    scanf ("%lf", &t);

    A = P * pow(1 + (r / n), n * t);
    printf ("\nЗагальна сума заробітку: %lf", A);
    printf ("\nСума чистого заробітку: %lf", A - P);

    return 0;
}


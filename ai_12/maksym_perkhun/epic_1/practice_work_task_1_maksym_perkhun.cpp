#include <cmath>
#include <cstdio>
int main()
{
    int n, t;
    float r, a, p;
    printf("Введіть основну суму інвестиції: ");
    scanf("%f", &p);
    printf("Введіть річну процентну ставку: ");
    scanf("%f", &r);
    printf("Введіть кількість нарахувань відсотків на рік: ");
    scanf("%d", &n);
    printf("Введіть час, на який гроші інвестуються, у роках: ");
    scanf("%d", &t);
    a = p * pow((1 + r / n), n * t);
    printf("Загальна сума інвестиції: ");
    printf("%.3f \n", a );
    printf("Cумa самого заробітку: ");
    printf("%.f", a - p);
    return 0;
}

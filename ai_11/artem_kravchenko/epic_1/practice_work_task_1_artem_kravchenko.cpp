#include <iostream>
#include <cmath>
using namespace std;
int main (){
     double A, P, r, n, t;

    printf("Основна сума інвестиції: ");
    scanf("%lf", &P);

    printf("Річна процентна ставка: ");
    scanf("%lf", &r);

    printf("Кількість нарахувань відсотків на рік: ");
    scanf("%lf", &n);

    printf("Час, на який гроші інвестуються, у роках: ");
    scanf("%lf", &t);

    A = P * pow( 1 + r / n, n*t );

    printf("Загальна сума інвестиції: %.2lf\n", A);
    printf("Сума самого заробітку: %.2lf\n", A - P);

    return 0;
}


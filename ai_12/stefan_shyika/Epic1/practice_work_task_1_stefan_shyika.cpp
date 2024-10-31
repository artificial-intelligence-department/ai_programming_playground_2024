#include <stdio.h>
#include <math.h>

int main(void){
    double A, P, r, earned; 
    int n, t;

    printf("Сума інвестиції: ");
    scanf("%lf", &P);

    printf("Процентна ставка у %%: ");
    scanf("%lf", &r);
    r /= 100;

    printf("Кількість років інвестування: ");
    scanf("%d", &t);

    printf("Кількість нарахувань на рік(1, 4, 12): ");
    scanf("%d", &n);

    A = P * pow((1 + r / n), n * t);
    earned = A - P;

    printf("---------------РЕЗУЛЬТАТИ-----------------\n");
    printf("Загальна сума: %.2lf \n", A);
    printf("Прибуток: %.2lf\n", earned);

}

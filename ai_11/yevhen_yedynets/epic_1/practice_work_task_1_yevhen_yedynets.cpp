#include <stdio.h>
#include <math.h>

int main(){
    
    int p, n, t;
    float r;

    printf("Початковий депозит: ");
    scanf("%d", &p);

    printf("Річна процентна ставка: ");
    scanf("%f", &r);
    r = r / 100;

    printf("Кількість нарахувань відсотків на рік: ");
    scanf("%d", &n);

    printf("Кількість років: ");
    scanf("%d", &t);
    
    float a = p * pow((r / n) + 1, n*t);

    printf("Загальна сума інвестиції: %.2f\n", a);
    printf("Ваш заробіток: %.2f\n", (a - p));

    return 0;
}

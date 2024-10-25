#include <stdio.h>
#include <math.h>

int main() {

    int n, t, p;
    float r, a;

    printf("Введіть суму для інвестиції  ");
    scanf("%i", &p);
    printf("Введіть кількість нарахувань на рік  ");
    scanf("%i", &n);
    printf("Введіть час на який інвестуються гроші у роках  ");
    scanf("%i", &t);
    printf("Введіть річну процентну ставку  ");
    scanf("%f", &r);
    
    printf("Вкладені кошти = %i\n", p);
    printf("Майбутня загальна сума інвестиції = %.2f\n", a);
    printf("Сума заробітку = %.2f\n", a-p);

    return 0;
}
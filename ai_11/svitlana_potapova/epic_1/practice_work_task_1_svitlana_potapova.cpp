#include <cmath>
#include <stdio.h>

int main()
{
    int n, t;
    double A, P, r;
    printf("Введіть основну суму інвестиції: ");
    scanf("%lf", &P);
    printf("Введіть річну процентну ставку (у вигляді десяткового дробу): ");
    scanf("%lf", &r); 
    printf("Введіть час, на який інвестуються гроші, в роках: ");
    scanf("%d", &t);

    printf("Оберіть кількість нарахувань відсотків на рік:\n");
    printf("1 - кожного місяця, 2 - кожного кварталу, 3 - кожного року.\n");
    scanf("%d", &n);

    switch(n){
        case 1:
        n = 12;
        break;

        case 2:
        n = 4;
        break;

        case 3:
        n = 1;
        break;

        default:
        printf("Обрано некорректний варіант.");
        return 1;

    }

    A = P * pow((1+r/n), n*t);
    printf("Вкладені кошти: %.2lf\n", P);
    printf("Загальна сума інвестиції: %.2lf\n", A);
    printf("Сума заробітку: %.2lf\n", A-P );

    return 0;

} 

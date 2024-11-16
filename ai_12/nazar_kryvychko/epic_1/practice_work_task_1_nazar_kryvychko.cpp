#include <stdio.h>
#include <math.h>

int main() {
    double P, r, A;
    int n, t;
    int option;

    printf("Введіть основну суму інвестиції (P): ");
    scanf("%lf", &P);

    printf("Введіть річну процентну ставку у %% (r): ");
    scanf("%lf", &r);
    r /= 100;  

    printf("Введіть термін інвестиції у роках (t): ");
    scanf("%d", &t);

    printf("Виберіть варіант нарахування відсотків:\n");
    printf("1. Щомісяця\n");
    printf("2. Щокварталу\n");
    printf("3. Щороку\n");
    printf("Ваш вибір (1/2/3): ");
    scanf("%d", &option);

    switch(option) {
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
            printf("Неправильний вибір!\n");
            exit(1);
    }

    A = P * pow((1 + r / n), n * t);

    printf("\nОсновна сума інвестиції: %.2f\n", P);
    printf("Річна процентна ставка: %.2f%%\n", r * 100);
    printf("Термін інвестиції: %d років\n", t);
    printf("Майбутня загальна сума інвестиції: %.2f\n", A);
    printf("Зароблені відсотки: %.2f\n", A - P);

    return 0;
}

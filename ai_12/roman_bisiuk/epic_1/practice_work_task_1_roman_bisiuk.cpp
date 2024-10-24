#include <stdio.h>
#include <math.h>

int main(){
    double A, P, r;
    int n, t;
    int option;

    printf("Введіть початкову суму інвестиції: ");
    scanf("%lf", &P);

    printf("Введіть процентну ставку: ");
    scanf("%lf", &r);
    r /= 100;

    printf("Введіть кількість років інвестування: ");
    scanf("%ld", &t);

    printf("Вкажіть варіант виплати відсотків:\n");
    printf("Введіть 1, для щомісячної виплати \n");
    printf("Введіть 2, для щоквартальної виплати \n");
    printf("Введіть 3, для щорічної виплати \n");
    scanf("%d", &option);

    switch(option){
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
            printf("Ви ввели некоректні дані");
            exit(1);
    }
 
    A = P * pow((1 + r / n), n * t);

    printf("*****************Результати****************\n");
    printf("Загальна сума: %.2lf \n", A);
    printf("Прибуток: %.2lf \n", A - P);

    return 0;
}
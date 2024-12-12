#include <stdio.h>
#include <math.h>

int main() {
    double p, r, t;
    int n;
    printf("Введіть основну суму інвестиції: ");
    scanf("%lf", &p);
    printf("Введіть річнy процентнy ставкy (у десятковій формі, тобто 5% = 0,05): ");
    scanf("%lf", &r);
    printf("Введіть час, на який гроші інвестуються (у роках): ");
    scanf("%lf", &t);
    
    printf("\nОберіть варіант виплати відсотків:\n");
    printf("1. Щомiсяця\n2. Щокварталу\n3. Щорічно\nВаш вибір: ");
    scanf("%d", &n);

    switch (n) {
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
            printf("Некоректний варіант виплати.\n");
            return 1;
    }
    
    double a = p*(pow((1+(r/n)),(n*t)));
    
    printf("\nОсновна сума інвестиції: %.3lf", p);
    printf("\nМайбутня загальна сума інвестиції разом із відсотками: %.3lf", a);
    printf("\nЗаробіток: %.3lf", (a-p));
    return 0;
}
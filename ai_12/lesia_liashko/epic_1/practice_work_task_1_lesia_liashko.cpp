#include <stdio.h>
#include <math.h>

int main() {
    double P, r, A, t;
    int n, option;

   do {

    // Введення даних
    printf("Введіть основну суму інвестиції (P): ");
    scanf("%lf", &P);
    printf("Введіть річну процентну ставку десятковим дробом: ");
    scanf("%lf", &r);
    printf("Введіть час (у роках): ");
    scanf("%lf", &t);
   
    // Вибір з переліку
    printf("Оберіть період виплат:\n");
    printf("1 - Щомісяця\n");
    printf("2 - Кожного кварталу\n");
    printf("3 - Щороку\n");
    scanf("%d", &option);
       if (option < 1 || option > 3) {
            printf("Такого варіанту немає у переліку, спробуйте ще раз\n");
        }
    } while (option < 1 || option > 3);

    switch (option) {
        case 1:
            n = 12;  // Щомісяця
            break;
        case 2:
            n = 4;   // Щосезону
            break;
        case 3:
            n = 1;   // Щороку
            break;
    }

    // Обрахунки
    A = P * pow(1 + (r / n), n * t);

   
    printf("Майбутня загальна сума інвестиції, включаючи відсотки, складає: %.3lf\n", A);

    return 0;
}

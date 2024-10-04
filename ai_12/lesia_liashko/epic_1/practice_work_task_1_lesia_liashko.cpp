#include <stdio.h>
#include <math.h>

int main() {
    double P, r, A, t;
    int n, option;

   do {

    // Input the initial principal (P), annual interest rate (r), time (t)
    printf("Введіть основну суму інвестиції (P): ");
    scanf("%lf", &P);
    printf("Введіть річну процентну ставку десятковим дробом: ");
    scanf("%lf", &r);
    printf("Введіть час (у роках): ");
    scanf("%lf", &t);
   
    // Choose the compounding frequency
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
            n = 12;  // Monthly compounding
            break;
        case 2:
            n = 4;   // Quarterly compounding
            break;
        case 3:
            n = 1;   // Annual compounding
            break;
    }

    // Formula for compound interest
    A = P * pow(1 + (r / n), n * t);

    // Output the result with formatting
    printf("Майбутня загальна сума інвестиції, включаючи відсотки, складає: %.3lf\n", A);

    return 0;
}

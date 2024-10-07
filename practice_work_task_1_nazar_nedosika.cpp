#include <stdio.h>
#include <math.h>

int main()
{
    double initial_amount;
    double rate;
    int charges_per_year;
    int years;
    int option;

    printf("Введіть початкову суму депозиту: ");
    scanf("%lf", &initial_amount);
    printf("Введіть річну відсоткову ставку (в %%): ");
    scanf("%lf", &rate);
    printf("Оберіть варіант виплати відсотків (1 - щороку, 2 - щокварталу, 3 - щомісяця): ");
    scanf("%d", &option);
    printf("Введіть кількість років: ");
    scanf("%d", &years);

    if(option == 1)
    {
        charges_per_year = 1;
    }
    else if (option == 2)
    {
        charges_per_year = 4;
    }
    else if (option == 3)
    {
        charges_per_year = 12;
    }

    double result;

    result = initial_amount * pow(1 + (rate / 100) / charges_per_year, charges_per_year * years);

    printf("Вкладені кошти: %.2f грн \n", initial_amount);
    printf("Загальна сума: %.2lf грн \n", result);
    printf("Зароблена сума: %.2f грн", result - initial_amount);

    return 0;
}
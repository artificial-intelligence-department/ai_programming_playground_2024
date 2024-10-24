#include <stdio.h>
#include <math.h>

using namespace std;

int main() 
{
    int invest, percperyear, time, choice;
    float percent;
    printf("Введіть суму інвестиції: \n");
    scanf("%d", &invest);
    printf("Введіть процентну ставку: \n");
    scanf("%f", &percent);

     percent /= 100.0;

    printf("\nВведіть варіант нарахування відсотків: \n");
    printf("\n1-Місяць ");
    printf("\n2-Квартал");
    printf("\n3-Рік\n");
    scanf("%i", &choice);

switch (choice)
{
case 1:
percperyear=12;
    break;
case 2:
percperyear=4;
    break;
case 3:
percperyear=1;
    break;
default:
printf("\n Неправильний вибір!");
exit(1);
}

    printf("Введіть на скільки часу інвестуються гроші(у роках): \n");
    scanf("%d", &time);


    float A= invest*pow(1+percent/percperyear,percperyear*time);

    printf("Ви вклали: %d\n", invest);
    printf("Загальна сума інвестиції: %.1f\n", A);
    printf("Сума заробітку: %.1f\n",(A-invest));
    return 0;
}
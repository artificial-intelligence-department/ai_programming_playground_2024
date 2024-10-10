#include <cmath> //Для матeматичних обчислень
#include <cstdio>  //Для того щоб вводити/ввиводити через printf та scanf
int main()
{
    int p, t, option;

    float r, n, a;

    printf("Введіть основну суму інвестиції: ");
    scanf("%d", &p);
    printf("Введіть річну процентну ставку: ");
    scanf("%f", &r);
    r /= 100;

    printf("Введіть термін інвестиції у роках (t): ");
    scanf("%d", &t);

    printf("Виберіть варіант нарахування відсотків:\n");
    printf("1. Щомісяця\n");
    printf("2. Щокварталу\n");
    printf("3. Щороку\n");
    printf("Ваш вибір (1/2/3): ");
    scanf("%d", &option);

    switch(option)
     {
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

    printf("Введіть кількість нарахувань відсотків на рік: ");
    scanf("%f", &n);
    printf("Введіть час, на який гроші інвестуються, y роках: ");
    scanf("%d", &t);

    a = p * pow((1 + r / n), n * t);  //Фунуція яка обчислює значення за математичною формулою

    printf("Загальна сума інвестицій: ");
    printf("%.3f\n", a );
    printf("Загальний заробіток: ");
    printf("%.3f", a - p);

    return 0;

}


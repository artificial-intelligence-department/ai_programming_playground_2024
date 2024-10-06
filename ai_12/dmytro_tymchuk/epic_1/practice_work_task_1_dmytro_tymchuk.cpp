#include<iostream>
#include <cstdio>
#include<math.h>

int main()
{
    double future_money, my_money, percent, time,number;

    /// введенння даних
    printf("Введіть суму вкладення: ");
    scanf("%lf", &my_money); 
    printf("Введіть відсоткові річну ставку: ");
    scanf("%lf", &percent); 
    printf("Введіть кількість нарахуваня відсотків на рік: ");
    scanf("%lf", &number); 
    printf("Введіть час на який гроші інвестуються: ");
    scanf("%lf", &time); 
    /// введенння даних

    future_money = my_money * pow(1 + (percent / number), number * time);//Обчислення кінцевої суми за формулою

    /// виведення даних
    printf("Вкладена сума: %.2lf \n", my_money);
    printf("Кінцква сума: %.2lf \n", future_money);
    printf("Заробіток: %.2lf \n", future_money - my_money);
    /// виведення даних

    return 0;
}
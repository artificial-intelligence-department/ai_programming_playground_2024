#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    // Декларація змінних
    double investmentMoney = 0;
    double interest = 0;
    double numOfPayouts = 0;
    double depositPeriod = 0;
    double sum = 0;

    // Введення змінних

    printf("Investment: ");
    scanf("%lf", &investmentMoney);
    printf("Annual rate (0<r<1): ");
    scanf("%lf", &interest);
    printf("Number of payouts: ");
    scanf("%lf", &numOfPayouts);
    printf("Deposit period: ");
    scanf("%lf", &depositPeriod);

    sum = investmentMoney * pow(1.0 + (interest / numOfPayouts), numOfPayouts * depositPeriod); // Формула розрахунку загальної суми

    printf("Money invested: %lf$\n", investmentMoney); // Інвестовані гроші
    printf("Final sum: %lf$\n", sum);                  // Загальна сума
    printf("Earnings: %lf$\n", sum - investmentMoney); // Сума заробітку

    return 0;
}
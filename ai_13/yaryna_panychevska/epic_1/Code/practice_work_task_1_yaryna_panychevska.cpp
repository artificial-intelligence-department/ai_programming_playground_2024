#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
//(A) - загальна сума після інвестування
//(P) - початкова сума
//(r) - річна ставка
//(n) - кількість нарахувань відсотків за рік
//(t)- кількість років
//(ClearProfit) - загальний прибуток
int main()
{
    double A, P, r, ClearProfit;
    int n, t;

    printf("Enter the initial investment amount:");
    scanf("%lf", &P);

    printf("Enter the annual interest rate (in decimal): ");
    scanf("%lf", &r);

    printf("Enter the number of times interest is compounded per year: ");
    scanf("%d", &n);

    printf("Enter the number of years the money is invested: ");
    scanf("%d", &t);

    A = P * pow(1 + r / n, n * t);
    ClearProfit = A - P;

    printf("Your total amount after investment: %lf\n", A);
    printf("Your initial investment amount: %lf\n", P);
    printf("Your clear profit amount is : %lf\n", ClearProfit);

    return 0;
}
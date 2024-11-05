#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

// (А)-загальна сума після інвестування
// (Р) - початкова сума
// (г) - річна ставка 
// (п) - кількість нарахувань відсотків за рік 
// (t) - кількість років
// (ClearProfit)-чистий прибуток

int main()
{
    double A, P, r, ClearProfit;
    int n, t;

    printf("Enter the initial investment amount: ");
    if (scanf_s("%lf", &P) != 1) {
        printf("Invalid input for the initial investment amount.\n");
        return 1;
    }

    printf("Enter the annual interest rate (in decimal): ");
    if (scanf_s("%lf", &r) != 1) {
        printf("Invalid input for the annual interest rate.\n");
        return 1;
    }

    printf("Enter the number of times interest is compounded per year: ");
    if (scanf_s("%d", &n) != 1) {
        printf("Invalid input for the number of times interest is compounded.\n");
        return 1;
    }

    printf("Enter the number of years the money is invested: ");
    if (scanf_s("%d", &t) != 1) {
        printf("Invalid input for the number of years.\n");
        return 1;
    }

    A = P * pow(1 + r / n, n * t);
    ClearProfit = A - P;

    printf("Your total amount after investment: %lf\n", A);
    printf("Your initial investment amount: %lf\n", P);
    printf("Your clear profit amount is: %lf\n", ClearProfit);

    return 0;
}
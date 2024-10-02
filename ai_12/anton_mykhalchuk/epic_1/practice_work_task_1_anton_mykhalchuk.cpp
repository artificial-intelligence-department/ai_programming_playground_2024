#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a, p, r;
    int n, t;
    printf("Enter principal amount of investment: ");
    scanf("%f", &p);

    printf("Enter annual percentage rate: ");
    scanf("%f", &r);

    printf("Enter number of interest charges per year: ");
    scanf("%d", &n);

    printf("Enter time for which the money is invested, in years: ");
    scanf("%d", &t);


    a = p * pow(1 + r/n/100, n*t);


    printf("\n\n\nThe total amount of the investment, given:\nPrincipal amount of the investment %.2f\nThe annual interest rate %.2f\%\nThe number of interest accruals per year %d\nand the time for which the money is invested %d years\nWill be equal: %.2f\n", p, r, n, t, a);
    printf("The amount of the earnings themselves: %.2f", a-p);

    return 0;
}
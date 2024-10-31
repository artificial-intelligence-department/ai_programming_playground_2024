#include <cmath>
#include <stdio.h>

int main() {
    int P, n, t;
    double A, r;
    
    printf("Enter the initial investment amount: ");
    scanf("%d", &P);
    printf("Enter the yearly interest rate (in decimal form): ");
    scanf("%lf", &r);
    printf("How often is the interest compounded per year? (monthly/quarterly/annually) (12/4/1): ");
    scanf(" %d", &n);
    printf("For how many years will the money be invested? ");
    scanf("%d", &t);

    A = P * pow((1 + r/n), (n * t));
    double profit = A - P;

    printf("_________________________\n");
    printf("Total amount after %d years: %.2lf \n", t, A);
    printf("Profit after %d years: %.2lf\n", t, profit);

    printf("You are investing %d for %d years at a %.2lf%% annual interest rate.\n", P, t, r * 100);
    printf("The interest is compounded %d times a year.\n", n);

    return 0;
}

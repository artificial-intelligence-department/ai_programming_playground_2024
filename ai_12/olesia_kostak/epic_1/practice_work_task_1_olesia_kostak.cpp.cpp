#include <stdio.h>
#include <math.h>

int main()
{
    double A, P;
    double r, n, t;

    printf("Enter principal amount of investment: ");
    scanf("%lf", &P);

    printf("Enter annual interest rate: ");
    scanf("%lf", &r);
    r = r / 100.0;

    printf("Enter the number of interest accruals per year: ");
    scanf("%lf", &n);

    printf("Enter time for which money is invested, in years: ");
    scanf("%lf", &t);

    // Calculating
    A = (P * (pow(1 + (r / n), n * t)));

    // Printing
    printf("____________________________________________________________\n");
    printf("Invested money : %lf\n", P);
    printf("Total investment amount : %lf\n", A);
    printf("Earnings : %lf\n", A - P);




    return 0;
}
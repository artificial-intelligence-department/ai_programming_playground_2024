#include <iostream>
#include <cmath>

int main()
{
    double A;
    double P;
    double r;
    double n;
    double t;
    double income;

    printf("Enter the amount of your deposit: ");
    scanf("%lf", &P);

    printf("Enter your annual interest rate(in percents): ");
    scanf("%lf", &r);

    printf("Enter the number of interest charges per year: ");
    scanf("%lf", &n);

    printf("Enter the time for which you invest(in years): ");
    scanf("%lf", &t);

    A = P * pow(1 + ((r/100) / n), n * t);
    income = A - P;

    printf("Your investment is: %0.21f\n", P);
    printf("Time period for which you invest is: %0.01f year(s) \n", t);
    printf("After this period, your funds will be: %0.21f\n", A);
    printf("Your earnings are: %0.21f\n", income);

    return 0;
}
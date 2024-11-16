#include <stdio.h>
#include <math.h>

int main()
 {
    double P, r, A;
    int n;
    double t;

    printf("Enter sum (P): ");
    scanf("%lf", &P);

    printf("Enter the annual interest rate (in decimal form, for example 0.05 for 5%%): ");
    scanf("%lf", &r);

    printf("Enter years (t): ");
    scanf("%lf", &t);

    printf("Choose (1 - Monthly, 2 - every quarter, 3 - Yearly): ");
    scanf("%d", &n);

    if (n == 1) 
    {
        n = 12;  
    }
    else if (n == 2) 
    {
        n = 4;  
    }
    else if (n == 3)
    {
        n = 1;   
    }
    else
    {
        printf("Wrong choice.\n");
        return 1;
    }

    A = P * pow((1 + r / n), n * t);

    printf("The main sum of the investment: %.2lf\n", P);
    printf("Total amount of investment with interest: %.2lf\n", A);
    printf("Amount of earnings: %.2lf\n", A - P);

    return 0;
}

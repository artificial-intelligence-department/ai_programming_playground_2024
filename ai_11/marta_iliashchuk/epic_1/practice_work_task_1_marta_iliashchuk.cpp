#include <stdio.h>
#include <math.h>

int main()
{
    int t, n;
    double A, P, r;

    printf("Enter your investment amount: \n");
    scanf("%lf", &P);
    printf("Enter annual interest rate: \n");
    scanf("%lf", &r);
    printf("Enter investment period per year: \n");
    scanf("%d", &t);
    
    do {
        printf("Enter the number of compounding periods per year (1) or per month(12) or per quartal (4): ");
        scanf("%d", &n);
    }
    while(n != 1 && n !=12 && n !=4);
    A = P * (pow((1+(r/n)), n*t));
    printf("Your investment amount: %.2lf\n", P);
    printf("Total investment amount: %.2lf\n", A);
    printf("Profit amount: %.2lf\n", A-P );

    return 0;
}
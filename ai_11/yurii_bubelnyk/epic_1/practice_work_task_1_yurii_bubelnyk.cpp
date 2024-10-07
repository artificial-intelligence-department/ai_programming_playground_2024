#include <stdio.h>
#include <math.h>

int main() {
    double P, r, t, A, earnings;
    int n;

    printf("Enter the principal amount of investment (P): ");
    scanf("%lf", &P);
    printf("Enter the annual interest rate (r) as a percentage: ");
    scanf("%lf", &r);
    printf("Enter the time of investment (t) in years: ");
    scanf("%lf", &t);
    
    printf("Choose an interest payout option:\n");
    printf("1 - Monthly\n");
    printf("2 - Quarterly\n");
    printf("3 - Annually\n");
    int option;
    scanf("%d", &option);

    switch (option) {
    case 1:
        n = 12;
        break;
    case 2:
        n = 4;
        break;
    case 3:
        n = 1;
        break;
    default:
        printf("Incorrect!\n");
        return 1;
    }


    r /= 100;
    
    A = P * pow((1 + r / n), n * t);
    
    earnings = A - P;

    printf("Total investment amount: %.2lf\n", A);
    printf("Earnings amount: %.2lf\n", earnings);

    return 0;
}

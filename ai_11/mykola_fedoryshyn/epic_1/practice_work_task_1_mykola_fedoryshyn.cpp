#include <iostream>
#include <string.h>
#include <cmath>

main(){
    int P, n;
    double r, t, A, power;

    printf("Enter deposit sum: ");
    scanf("%d", &P);

    printf("Annual interest rate: ");
    scanf("%lf", &r);

    printf("Number of profits: ");
    scanf("%d", &n);

    printf("Time(in years): ");
    scanf("%lf", &t);

    A = P * pow((1 + (r / n)), (n * t));;

    printf("Invested funds: %d \n", P);
    printf("General sum of funds: %.3lf \n", A);
    printf("Sum of income: %.3lf \n", (A-P));
    return 0;

}

#include <stdio.h>
#include <math.h>
int main (){
    double A, P, r, n, t;

    printf("Enter the principal amount of the investment:" );
    scanf("%Lf", &P);

    printf("Еnter the annual interest rate (in decimal form): ");
    scanf("%Lf", &r);

    printf("Enter the number of interest charges per year: ");
    scanf("%Lf", &n);

    printf("Enter the time for which money is invested, in month: ");
    scanf("%Lf", &t);

    A = P * pow((1 + r/n), n*t);

    printf("\n Total investment amount %Lf", A);
    printf("\n Amount of net earnings %Lf", A - P);

    return 0;
}

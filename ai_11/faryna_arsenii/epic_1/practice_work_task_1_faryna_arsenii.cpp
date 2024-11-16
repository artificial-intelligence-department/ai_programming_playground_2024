#include <stdio.h>
#include <cmath>
int main (){
    double P, A;
    int n, t;
    float r;

    printf("Enter the principal amount of the investment: " );
    scanf("%Lf", &P);

    printf("Еnter the annual interest rate in decimal form: ");
    scanf("%f", &r);

    printf("Enter the number of interest charges per year: ");
    scanf("%d", &n);

    printf("Number of years: ");
    scanf("%d", &t);

    A = P * pow((1 + r/n), n*t);

    printf("\n Your income is %Lf", A);
    printf("\n Clean income %.4f ", A - P);

    return 0;
}

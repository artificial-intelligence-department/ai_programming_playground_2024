#include <bits/stdc++.h>
using namespace std;
int main() {
    float A,r,n,t,P;

    printf("Enter the principal amount of the investment:");
    scanf("%f",&P);
    printf("Enter the annual interest rate:");
    scanf("%f",&r);
    printf("Enter the number of interest charges per year:");
    scanf("%f",&n);
    printf("Enter the time for which the money is invested, in years:");
    scanf("%f",&t);

    A=P * pow(( 1 + ( r / n ) ) ,n * t );

    printf("invested funds: ");
    printf("%.4f\n",P);
    printf("the total investment amount: ");
    printf("%.4f\n",A);
    printf("the amount of earnings: ");
    printf("%.4f\n",A-P);
}

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,t,P;
    float A,r;

    printf("Enter the principal amount of the investment:");
    scanf("%d",&P);
    printf("Enter the annual interest rate:");
    scanf("%f",&r);
    printf("Enter the number of interest charges per year:");
    scanf("%d",&n);
    printf("Enter the time for which the money is invested, in years:");
    scanf("%d",&t);

    A=P * pow(( 1 + ( r / n ) ) ,n * t );

    printf("invested funds: ");
    printf("%d\n",P);
    printf("the total investment amount: ");
    printf("%f\n",A);
    printf("the amount of earnings: ");
    printf("%f\n",A-P);
}

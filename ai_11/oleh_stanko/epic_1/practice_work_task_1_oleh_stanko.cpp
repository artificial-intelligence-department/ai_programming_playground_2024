#include <stdio.h>
#include <math.h>

int main()
{
    int P;
    printf("Enter sum of investments: ");
    scanf("%i", &P);

    double r;
    printf("Enter annual interest rate(0..100): ");
    scanf("%lf", &r);
    r/=100.0;
    int n;
    printf("Enter the number of interest charges per year: ");
    scanf("%i", &n);

    int t;
    printf("Enter time for which the money is invested, in years: ");
    scanf("%i", &t);
    
    double x=1+r/n;
    double A=P*pow(x,n*t);
    A=round(A*100)/100;
    
    printf("_________information_______\n");
    printf("invested money ==%i\n",P);
    printf("____________________________\n");
    printf( "total investment amount=%.2lf\n",A);
    printf("____________________________\n");
    printf( "the amount of earnings=%.2lf",(A-P));
} 

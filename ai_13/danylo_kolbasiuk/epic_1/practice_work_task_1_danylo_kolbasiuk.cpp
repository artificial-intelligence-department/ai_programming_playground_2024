#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
using namespace std;
static int P, t, n, r;
void formula()
{
    double temp0=double(r)/100;
    double temp1=1+(temp0/double(n));
    double temp2=n*t;
    double temp3=pow(temp1, temp2);
    double A=P*temp3;
    double S=A-double(P);
    printf("Main sum of investment: %u", P);
    printf("\n");
    printf("Interest: %u", r);
    printf("%%");
    printf("\n");
    printf("Future sum of investment: %0.2f", A);
    printf("\n");
    printf("Profit: %0.2f", S);
}
void input()
{
    printf("Enter main sum of investment: ");
    do {
        scanf("%u", &P);
        if(P<1)  {
        printf("Please enter a positive integer: ");     
    }
    } while (P<1);
    printf("Enter the depositing time (in years): ");
    do {
        scanf("%u", &t);
        if(t<1)  {
        printf("Please enter a positive integer: ");     
    }
    } while (t<1);
    printf("Enter the percentage of interest: ");
    do {
        scanf("%u", &r);
        if(r<1)  {
        printf("Please enter a positive integer: ");     
    }
    } while (r<1);
    do {
        printf("Enter the amount of payments per year (1, 4 or 12): ");
        scanf("%u", &n);
        if (!((n==1)||(n==4)||(n==12)))
        {
        printf("Invalid amount of payments, try again.");
        printf("\n");
        }
    } while (!((n==1)||(n==4)||(n==12)));
}
int main()
{
    input();
    formula();
}
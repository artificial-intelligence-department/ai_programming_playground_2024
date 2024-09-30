#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
// This code calculates the profit you would get from depositing some money into the bank after a specific period of time.
// Main sum of deposit is P, interest is r, amount of payments per year is n(only works if n=1, 4 or 12), depositing time in years is t.
// The code uses this formula to calculate the profit: A=P*(1+(r/(100*n))^(n*t))
// The 100 is included because the input for interest is an integer, but we have to convert it to a decimal instead of a percentage (1%=0.01)
// The code also checks whether all the input values are positive integers. Otherwise, the code will output a warning and will ask to type in another value.
// I also tried to modify the code to check for incorrect data types, but I couldn't get it to work :/
static int P, t, n, r;
void formula()
{
    double temp0=double(r)/100;
    double temp1=1+(temp0/double(n));
    double temp2=n*t;
    double temp3=pow(temp1, temp2);
    double A=P*temp3;
    double S=A-double(P);
    printf("Main sum of deposit: %u", P);
    printf("\n");
    printf("Interest: %u", r);
    printf("%%");
    printf("\n");
    printf("Depositing time: %u", t);
    printf("\n");
    printf("Amount of payments per year: %u", n);
    printf("\n");
    printf("Future sum of deposit: %0.2f", A);
    printf("\n");
    printf("Profit: %0.2f", S);
}
void input()
{
    printf("Enter main sum of deposit: ");
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
    return 0;
}
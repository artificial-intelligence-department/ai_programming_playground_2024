#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double r, P;
    int n, t;
    do
    {
       printf("Enter the amount of money you want to invest:");
       scanf("%lf", &P);
    } while(P<=0);
    do
    {
     printf("Enter the annual interest rate in decimal form:");
     scanf("%lf", &r);
    } while (r<0);
    do 
    {
     printf("Enter the number of interest charges per year:");
     scanf("%d", &n);
    } while (n!=1 && n!=4 && n!=12);
    do
    {
     printf("Enter the years for how much money is invested:");
     scanf("%d", &t);
    } while (t<0);
    double A = P* pow(1+r/n, n*t);
    double earnings = A - P;
    printf("You invested: %.3lf\n", P);
    printf("Sum of your investion is: %.3lf\n", A);
    printf("You've earned: %.3lf", earnings);
    
 
    

    return 0;
}
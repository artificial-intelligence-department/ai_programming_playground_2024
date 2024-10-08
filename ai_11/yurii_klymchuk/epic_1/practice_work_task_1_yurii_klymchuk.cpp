#include <iostream>
#include <cmath>

using namespace std;
//An=P*(1+r/n)^n*t

int main()
{
    double interest_rate, deposit, number_of_times, years;    
    printf("Compound interest calculator\nEnter your deposit: ");
    scanf("%lf", &deposit);
    printf("Enter interest rate: ");
    scanf("%lf", &interest_rate);
    printf("Enter the number of interest charges per year: ");
    scanf("%lf", &number_of_times);
    printf("Deposit term(in years): ");
    scanf("%lf", &years);
    double summ = round(deposit*pow(1 + (interest_rate/number_of_times), (number_of_times*years)));
    printf("Your deposit was %lf .\nYour final sum will be: %lf", deposit, summ);
    double profit = summ - deposit;
    printf("\nYour profit will be: %lf", profit);
    return 0;
}
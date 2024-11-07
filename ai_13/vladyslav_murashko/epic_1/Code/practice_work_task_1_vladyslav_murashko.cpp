#include <stdio.h>
#include <cmath>

int main()
{
    double investitions;
    float annual_rate;
    short time_years, payment_per_year;
    double result; // Майбутня загальна сума інвестиції, включаючи відсотки

    printf("Enter the base investment amount ($): ");
    scanf("%lf", &investitions);
    printf("Enter the annual rate (5%% = 0.05): ");
    scanf("%f", &annual_rate);
    do
    {
        printf("Enter the payment frequency per year (1,4 or 12): ");
        scanf("%d", &payment_per_year);
    } while (payment_per_year != 1 && payment_per_year != 4 && payment_per_year != 12);
    
    
    printf("Enter the investition time (in years): ");
    scanf("%d", &time_years);

    result = investitions * pow(1 + (double)annual_rate / payment_per_year, (int)payment_per_year * time_years);

    printf("\nBase investment amount: %0.2lf$\n",investitions);
    printf("Annual rate: %0.1f%%\n",annual_rate*100);
    printf("Payment frequency per year: %d time(s)\n",payment_per_year);
    printf("Investition time: %d years\n",time_years);
    printf("The future total amount of the investment, including interest is %0.2lf$\n",result);
    printf("Total gain: %0.2lf$\n",result - investitions);

    return 0;
}
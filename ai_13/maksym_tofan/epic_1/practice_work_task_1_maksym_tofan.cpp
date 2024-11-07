#include <stdio.h>
#include <math.h>

int main()
{
    double initial_amount, rate, result;
    int charges_per_year, years, option;

    // Input from user
    printf("Enter the initial deposit amount: ");
    scanf("%lf", &initial_amount);
    printf("Enter the annual interest rate (in %%): ");
    scanf("%lf", &rate);
    printf("Choose interest payout option (1 - annually, 2 - quarterly, 3 - monthly): ");
    scanf("%d", &option);
    printf("Enter the number of years: ");
    scanf("%d", &years);

    // Determine compounding frequency based on user option
    switch (option)
    {
        case 1:
            charges_per_year = 1;   // Annually
            break;
            charges_per_year = 4;   // Quarterly
            break;
        case 3:
            charges_per_year = 12;  // Monthly
            break;
        default:
            printf("Invalid option selected.\n");
            return 1; // Exit if the option is invalid
    }

    // Calculate total amount with compound interest
    result = initial_amount * pow(1 + (rate / 100) / charges_per_year, charges_per_year * years);

    // Output results
    printf("Initial deposit: %.2f\n", initial_amount);
    printf("Total amount after %d years: %.2lf\n", years, result);
    printf("Earned interest: %.2f\n", result - initial_amount);

    return 0;
}

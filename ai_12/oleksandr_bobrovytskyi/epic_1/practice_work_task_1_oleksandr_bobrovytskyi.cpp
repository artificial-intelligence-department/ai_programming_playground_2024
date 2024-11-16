#include <stdio.h>
#include <math.h>

int main()
{   
    float AnnualInterest = 0.05;
    short int NumOfCompoundingPeriods;
    double AmountInvested;
    int AmountOfYears;
    short int temp;

    printf("Choose the number corresponding to the compounding period:\n");
    printf("Every month = 1\n");
    printf("Every quarter = 2\n");
    printf("Every year = 3\n");

    do
    {
        scanf("%d", &temp);
        switch (temp)
        {
            case 1:
                NumOfCompoundingPeriods = 12;
                break;
            case 2:
                NumOfCompoundingPeriods = 4;
                break;
            case 3:
                NumOfCompoundingPeriods = 1;
                break;
            default:
                printf("Invalid value, try again.\n");
        }
    } while (!(temp == 1 || temp == 2 || temp == 3));

    printf("Enter the amount that you want to put in = ");
    scanf("%lf", &AmountInvested);

    printf("Enter the amount of time(in whole years) for which money will be invested = ");
    scanf("%d", &AmountOfYears);

    double InterestRate = 1 + (AnnualInterest/NumOfCompoundingPeriods);

    int TotalNumOfCompoundingPeriods = AmountOfYears * NumOfCompoundingPeriods ;

    double FutureAmountOfMoney = AmountInvested * pow(InterestRate , TotalNumOfCompoundingPeriods);

    printf("Initial amount invested = %lf\n", AmountInvested );
    printf("Initial amount of money plus interest = %lf\n", FutureAmountOfMoney );
    printf("Clear profit = %lf\n", FutureAmountOfMoney - AmountInvested );

    return 0;
}
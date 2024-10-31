#include <stdio.h>
#include <math.h>
int main() 
{
    double P, r, A;
    int n;
    int t;
    printf("Starting investment (P): ");
    scanf("%lf", &P);
    printf("Interest rate (0.01 = 1 percent, 0.10 = 10 percents): ");
    scanf("%lf", &r);
    printf("Number of interest charges per 1 year (1 for year, 4 for quarter, 12 for every month): ");
    scanf("%d", &n);
    printf("Time for which money are invested (in years): ");
    scanf("%d", &t);
    A = P * pow((1 + r/n), n*t);
    printf("Investment: %.2lf\n", P);
    printf("Investment with percentages: %.2lf\n", A);
    printf("Profit: %.2lf\n", A - P);

    return 0;
}

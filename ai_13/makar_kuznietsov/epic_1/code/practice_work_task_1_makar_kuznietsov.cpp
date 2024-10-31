#include <cmath>
#include <stdio.h>

int main()
{
    double a, p, t, per, i, r, n;
    do
    {
        printf("Enter period (1 = month; 2 = quarter; 3 = year) and for how long: ");
        scanf("%lf %lf", &per, &i);
    } while ((per != 1 && per != 2 && per != 3) || (i <= 0));

    if (per == 1)
    {
        t = i / 12;
        n = 12;
    }
    else if (per == 2)
    {
        t = i / 4;
        n = 12;
    }
    do
    {
        printf("How many to invest (enter positive number): ");
        scanf("%lf", &p);
    } while (p <= 0);
    do
    {
        printf("Enter annual percentage (enter positive number): ");
        scanf("%lf", &r);
    } while (r <= 0);

    r = r / 100;

    a = p * std::pow(1 + r / n, n * t);
    printf("Amount invested: %lf\n", p);
    printf("Final amount: %lf\n", a);
    printf("Your profit: %lf\n", a - p);
}

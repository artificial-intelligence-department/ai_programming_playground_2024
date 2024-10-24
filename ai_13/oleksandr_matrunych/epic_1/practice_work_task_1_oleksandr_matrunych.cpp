#include <stdio.h>
#include <math.h>

int main() {

    // Вводимо змінні
    double P, r, A, profit;
    int n, t;

    // Вводимо дані
    printf("Enter the amount of the investment: ");
        scanf("%lf", &P);
    printf("Enter the annual interest rate (as a decimal, e.g., 0.03): ");
        scanf("%lf", &r);
    printf("Enter the number of interest charges per year: ");
        scanf("%d", &n);
    printf("Enter the time for which the money is invested, in years: ");
        scanf("%d", &t);

    A = P * pow((1 + r / n), n * t); // Розрахунок кінцевої суми
    profit = A - P;  // Наш прибуток

    // Виводимо результат
    printf("________________________________________________________________\n");
    printf("Money invested: %.2f\n", P);
    printf("Annual interest rate: %.2f%%\n", r * 100);
    printf("Interest charges per year: %d\n", n);
    printf("Investment duration: %d years\n", t);
    printf("After %d years with %d periods per year, you will have: %.2lf\n", t, n, A);
    printf("Your profit: %.2f\n\n\n", profit);

    return 0;
}
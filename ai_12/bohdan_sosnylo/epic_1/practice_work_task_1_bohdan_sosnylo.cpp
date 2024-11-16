#include <iostream>
#include <stdio.h>
#include <math.h>

int main() {
    double P, r, A, earnings;
    int n, t;

    // Вводимо дані
    printf("Enter the principal amount of the investment (P): ");
    scanf("%lf", &P);
    printf("Enter the annual interest rate (in percent): ");
    scanf("%lf", &r);
    printf("Enter the number of interest charges per year (n): ");
    scanf("%d", &n);
    printf("Enter the investment term in years (t): ");
    scanf("%d", &t);

    // Перетворюємо річну процентну ставку з відсотків у десяткову форму
    r = r / 100;

    // Обчислюємо загальну суму інвестиції
    A = P * pow((1 + r/n), (n*t));

    // Обчислюємо суму заробітку
    earnings = A - P;

    // Виводимо результати
    printf("\n--- Results ---\n");
    printf("The principal amount of the investment(P): %.2f\n", P);
    printf("Annual interest rate(r): %.2f%\n", r * 100);
    printf("Number of accruals per year(n): %d\n", n);
    printf("Investment term (t): %d years\n", t);
    printf("Total amount of investment(A): %.2f\n", A);
    printf("Amount of earnings: %.2f\n", earnings);

    return 0;
}

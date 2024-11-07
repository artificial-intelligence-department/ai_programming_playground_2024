#include <cstdio>
#include <cmath>  // Для функції pow(піднесення в степінь)

int main() {
    // Оголошуємо наші змінні, і просимо користувача надати їм значення
    double P, r, t, n, A, profit;
    printf("Enter your deposit: ");
    scanf("%lf", &P);

    printf("Enter your annual interest rate(in %%): ");
    scanf("%lf", &r);

    printf("Enter your investment time(years): ");
    scanf("%lf", &t);

    printf("Enter your amount of interest payments per year: ");
    scanf("%lf", &n);

    // Формула складних відсотків
    A = P * pow(1 + ((r / 100) / n), n * t);  
    profit = A - P;  

    // Виведення результатів
    printf("Your investment is %f\n", P);
    printf("After %0.2lf years we will get %0.2lf\n", t, A);
    printf("Your profit is %0.2lf\n", profit);

    return 0;
}
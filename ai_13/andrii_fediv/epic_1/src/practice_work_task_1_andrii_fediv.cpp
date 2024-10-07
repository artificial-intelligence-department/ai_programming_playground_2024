#include <stdio.h>
#include <math.h>

#define RESET   "\033[0m"  // Скидання кольору
#define GREEN   "\033[32m" // Зелений
#define YELLOW  "\033[33m" // Жовтий
#define MAGENTA "\033[35m" // Магента

int main() {
    double P, r, A, earnings;
    int n, t;

    // Введення даних
    printf(GREEN "Enter the principal amount of the investment: " RESET);
    scanf("%lf", &P);

    printf(GREEN "Enter the annual interest rate (in decimal form, i.e. 5%% = 0.05): " RESET);
    scanf("%lf", &r);

    printf(GREEN "Enter the number of interest charges per year (1/4/12): " RESET);
    scanf("%d", &n);

    printf(GREEN "Enter the time for which the money is invested, in years: " RESET);
    scanf("%d", &t);

    // Обчислення фінальної суми
    A = P * pow((1 + r / n), n * t);
    earnings = A - P;  // Обчислення заробітку

    // Виведення результату
    printf(YELLOW "\n--- Investment Summary ---\n");
    printf(MAGENTA "Principal amount: " RESET); printf(YELLOW "%.2f\n" RESET, P);
    printf(MAGENTA "Annual interest rate: " RESET); printf(YELLOW "%.2f\n" RESET, r);
    printf(MAGENTA "Interest charges per year: " RESET); printf(YELLOW "%d\n" RESET, n);
    printf(MAGENTA "Investment duration: " RESET); printf(YELLOW "%d years\n" RESET, t);
    printf(MAGENTA "Total amount after %d years: " RESET, t); printf(YELLOW "%.2f\n" RESET, A);
    printf(MAGENTA "Total earnings (profit): " RESET); printf(YELLOW "%.2f\n" RESET, earnings);

    return 0;
}

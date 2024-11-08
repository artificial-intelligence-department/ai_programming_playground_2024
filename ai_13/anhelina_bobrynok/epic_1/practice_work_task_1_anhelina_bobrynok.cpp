#include <cstdio>
#include <cmath>

int main() {
    //отримання данних
    int P, n, t;
    printf("Enter the investment amount: ");
    scanf("%i", &P);

    double r;
    printf("Enter the annual interest rate (if 5%%, enter 5): ");
    scanf("%lf", &r); 

    r = r / 100;

    printf("Enter the number of interest charges per year: ");
    scanf("%i", &n);

    printf("Enter the time for which money is invested (in years): ");
    scanf("%i", &t);

    //розрахунки
    double A = P * pow(1 + r / n, n * t);

    //результат
    printf("Final result:\n");
    printf("Invested amount: %i\n", P);
    printf("Investment result: %.2f\n", A); 
    printf("The amount of earnings: %.2f\n", A - P);

    printf("\nPress Enter to exit...");
    getchar(); 
    getchar();

    return 0;
}

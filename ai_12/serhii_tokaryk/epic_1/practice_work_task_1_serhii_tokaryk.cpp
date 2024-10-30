#include <cstdio>
#include <cmath> 
int main() {

    double P , r , n , t , A , income;

    printf("Enter your deposit amount: ");
    scanf("%lf", &P);

    printf("Enter your annual interest rate (in percent): ");
    scanf("%lf", &r);

    printf("Enter the number of interest charges per year: ");
    scanf("%lf", &n);

    printf("Enter the time for which you invest (in years): ");
    scanf("%lf", &t);

    // Формула складних відсотків
    A = P * pow(1 + ((r / 100) / n), n * t);
    income = A - P;

    // Виведення результатів
    printf("Your investment is %0.2lf\n", P);
    printf("The period for which you invest is %0.0lf year(years) \n", t);
    printf("After this time, your funds will be added %0.2lf\n", A);
    printf("Your earnings are %0.2lf\n", income);

    return 0;
}
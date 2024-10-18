#include <stdio.h>
#include <math.h>

double calculate_compound_interest(double P, double r, int n, int t) 
{
    double A = P * pow(1 + r / n, n * t);
    return A;
}

int main() {
    double P;
    double r;  
    int n;
    int t;     

    printf("Введіть основну суму інвестицій (P): ");
    scanf("%lf", &P);

    printf("Введіть річну процентну ставку (r): ");
    scanf("%lf", &r);

    printf("Введіть кількість нарахувань на рік (n): ");
    scanf("%d", &n);

    printf("Час,на який гроші інвестуються (роках) (t): ");
    scanf("%d", &t);

    double result = calculate_compound_interest(P, r, n, t);

    printf("Кінцева сума: %.2f .\n", result);

    return 0;
}
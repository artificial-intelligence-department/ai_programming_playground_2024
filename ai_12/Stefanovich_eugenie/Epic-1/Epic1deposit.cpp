#include <iostream>
#include <cmath> 
using namespace std;

int main() {

    double P, r, A;
    int n, t;

    
    printf("Введіть початкову суму інвестиції (P): ");
    scanf("%lf", &P); // double

    printf("Введіть річну процентну ставку (r): ");
    scanf("%lf", &r); // double
    
    printf("Введіть кількість нарахувань відсотків на рік (n): ");
    scanf("%d", &n); //  int

    printf("Введіть кількість років (t): ");
    scanf("%d", &t); //  int

    
    A = P * pow(1 + r / n, n * t);

   
    printf("\n-------------------------------\n");
    printf("Початкова сума інвестиції (P): %.2f грн\n", P);
    printf("Річна процентна ставка (r): %.2f%%\n", r * 100); 
    printf("Кількість нарахувань відсотків на рік (n): %d\n", n);
    printf("Кількість років інвестиції (t): %d\n", t);
    printf("-------------------------------\n");
    printf("Загальна сума інвестиції (A): %.2f грн\n", A);
    printf("Сума заробітку: %.2f грн\n", A - P);

    return 0;
}

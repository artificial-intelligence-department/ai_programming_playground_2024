#include <stdio.h>
#include <cmath>
int main(){
    double P,A;
    float r;
    int n,t;
    printf("How much would you like to invest? ");
    scanf("%lf", &P);
    printf("Percentage in decimal: ");
    scanf("%f", &r);
    printf("The number of profits per year: ");
    scanf("%d", &n);
    printf("Number of years: ");
    scanf("%d", &t);
    A = P * pow((1 + r/n), n*t);
    printf("-------------------------\n");
    printf("Money invested: %.2f\n", P);
    printf("Percentage: %.2f%%\n", (r*100));
    printf("After %d years with profits %d times a year you will have: %.4lf\n", t, n, A);
    printf("So, the clean income is %.4f\n", A - P);
    
    return 0;
}
#include <stdio.h>
#include <math.h>

int main() {
    int n, t, p;
    float r, a;

    printf("enter sum for invest ");
    scanf("%i", &p);

    printf("enter number money on year   ");
    scanf("%i", &n);

    printf("enter time for how much   ");
    scanf("%i", &t);

    printf("enter persent   ");
    scanf("%f", &r);

    a = p * pow(1 + r / 100, t);

 
    printf("input = %i\n", p);
    printf("future sum of investition = %.2f\n", a);
    printf("doxid = %.2f\n", a - p);

    return 0;
}

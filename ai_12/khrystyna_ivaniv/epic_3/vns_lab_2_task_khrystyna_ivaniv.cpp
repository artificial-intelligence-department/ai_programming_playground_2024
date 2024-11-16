#include <stdio.h>
#include <math.h>

int main()
{

    float sum = 0;
    int n = 1;
    float limit = 0.0001;
    float a;

    do
    {
        a = 1 / pow(2, n) + 1 / pow(3, n);
        sum += a;
        n++;
    }

    while (a >= limit);
    printf("The sum of the series: %.4f", sum);

    return 0;
}
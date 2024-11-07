#include <stdio.h>
#include <cmath>

int main()
{
    //float epc = 0.0001;
    int num;
    printf("Input num to calculate series num: ");
    scanf("%d", &num);
    float counter = 0;
    
    for(int n = 1; n <= num; n++)
        {
            float a_n = pow(-1, n - 1)/ pow(n, n);
            counter += a_n;
        }
    printf("Final result of calculating: %.4f", counter);

    return 0;

}
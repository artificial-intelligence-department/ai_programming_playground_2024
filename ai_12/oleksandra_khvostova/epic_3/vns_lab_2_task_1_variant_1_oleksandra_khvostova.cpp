#include <stdio.h>

double countSum (double num){
    double An;
    double sum=0;
    An=1.0/((3.0*num-2.0)*(3.0*num+1.0));
    sum+=An;
    for(int n=1; n<=num; n++){
        An*=(3.0*n-2.0)/(3.0*n+4.0);
        sum+=An;
    }
    printf("Sum of the of the series is %.4lf", sum);
    return sum;
}

int main(){
    double n;
    printf("Enter the value of n: ");
    scanf("%lf", &n);
    countSum(n);
    return 0;
}
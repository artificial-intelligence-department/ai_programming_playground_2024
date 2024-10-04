#include <cstdio>
#include <cmath>

int main(){
    float P, r, n, t;
    printf("Enter investment amount: ");
    scanf("%f", &P);
    printf("Enter interest: ");
    scanf("%f", &r);
    printf("Number of charges per year: ");
    scanf("%f", &n);
    printf("Enter the investment duration: ");
    scanf("%f", &t);

    float yield = P * pow(1 + r/n, n*t);
    float totalProfit = yield - P;

    
    
    printf("The future total amount of the investment: %.3f", yield);

    printf("\nTotal profit: %.3f", totalProfit);
    return 1;
}

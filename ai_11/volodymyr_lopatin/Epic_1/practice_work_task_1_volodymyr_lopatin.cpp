#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main() {
    int starting;
    float percent;
    int add;
    int time;
    int power;
    float scope;
    float result;
    float income;
    
    printf("Enter the initial: ");
    scanf("%i", &starting);
    printf("Enter the interest rate': ");
    scanf("%f", &percent);
    percent /= 100; 
    printf("Enter the amount of charges per year(1/3/12): ");
    scanf("%i", &add);
    switch (add) {
        case 1:
        break;
        case 3:
        break;
        case 12:
        break;
        default:
        exit(0);
    }
    scope = 1 + (percent / add);
    printf("Enter the amount of time for your investment in years: ");
    scanf("%i", &time);
    power = add * time;
    result = starting * pow(scope , power);
    printf("Your initial ivestment is: %i \n", starting);
    printf("Your total income will be: %.2f \n", result);
    income = result - (float)starting;
    printf("Your income will be: %0.2f", income);


    return 0;
}

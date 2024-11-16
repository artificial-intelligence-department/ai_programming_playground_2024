#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

// A = P * (1 + r/n)**(n*t)
// A - майбутня загальна сума, включаючи відсотки 
// P - основна сума інвестицій
// r - річна процентна ставка
// n - кількість нарахувань відсотків за рік
// t - час інвестування у роках

int main() {

    int Deposit;
    float Percentage;
    int TimesPerYear;
    int Years;
    float Profit;

    printf("Enter deposit: ");
    scanf("%d", &Deposit);
    printf("Enter persents: ");
    scanf("%f", &Percentage);
    printf("Enter how many times per year (1, 4 or 12): ");
    scanf("%d", &TimesPerYear);
    printf("Enter amount of years: ");
    scanf("%d", &Years);

    Profit = Deposit * pow((1 + Percentage/TimesPerYear), (TimesPerYear * Years));

    printf("Deposit was: %d\n", Deposit);
    printf("Percentage were: %f\n", Percentage);
    printf("Times per year were: %d\n", TimesPerYear);
    printf("Total years were: %d\n", Years);
    printf("Total profit: %f\n", Profit);

    return 0;
}
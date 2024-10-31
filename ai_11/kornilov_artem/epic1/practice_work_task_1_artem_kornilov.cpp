#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;
int main() {
int invested;
float percentage;
float payoutsNum;
int yearsNum;
int overall;

printf ("Enter the desired amount of money to invest: \n");
scanf  ("%d", &invested);

printf ("Enter the yearly payout percent: \n");
scanf  ("%f", &percentage);

printf ("Enter the desired number of years you invest for: \n");
scanf  ("%d", &yearsNum);

while (!((payoutsNum == 12) || (payoutsNum == 4) || (payoutsNum == 1))) {
printf ("Enter the desired number of payouts per year(either 12, 4 or 1): \n");
scanf  ("%f", &payoutsNum);
}
float base = 1 + (percentage / payoutsNum);
int exponent = payoutsNum * yearsNum;
overall = invested * pow(base, exponent);
printf ("Your overall amount of money would be: %d", overall);

return 0;
}
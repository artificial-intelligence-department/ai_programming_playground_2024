#include <iostream>
#include <cstdio>
#include <cmath>


int main()
{
  int deposit;
  float result;
  float interest;
  int paymentsfr;
  int time;
  float income;


  printf("Enter the sum of deposit: ");
  scanf("%d", &deposit);

  printf("Enter the interes rate: ");
  scanf("%f", &interest);

  printf("Enter how much times a year, you want to take income (1 - once a year, 4 - every quartal, 12 - every month): ");
  scanf("%d", &paymentsfr);

  printf("Enter time(years) you want to lay deposit for: ");
  scanf("%d", &time);


  interest = interest / 100;
  result = deposit * pow((1 + (interest / paymentsfr)), (paymentsfr * time));
  income = result - deposit;


  printf("The sum of the deposit is: %d; the final sum of the investition is: %.3f; your income from the deposit is: %.3f    ", deposit, result, income);


  system("pause");
  return 0;

}

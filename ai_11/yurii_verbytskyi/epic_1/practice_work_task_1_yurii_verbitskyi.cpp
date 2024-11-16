#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std; 


int main (){

double P; // sum of investments
double r; // year percent stake
int n; // number of interest accruals per year
int t; // period of investment
double A; // result

printf("Enter sum of investments: ");
scanf("%lf", &P);


printf("Enter year percent stake: ");
scanf("%lf", &r);

printf("Enter number of interest accruals per year:\n Every month(12)\n Every querter(4)\n Every year(1)\n: ");
scanf("%d", &n);

printf("Enter period of investments: ");
scanf("%d", &t);

A = P*pow(1+r/n, n*t);

printf("Sum of investments: %2.lf\n", P);
printf("The final investment amount: %.2lf\n", A);
printf("Profit: %2.lf\n", A-P);


    return 0;
}






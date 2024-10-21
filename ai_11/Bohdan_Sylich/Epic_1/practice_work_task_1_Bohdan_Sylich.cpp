#include <stdio.h> 
#include <math.h> 
 
int main() { 
 int invest, procyear, time;
 float procent;
 printf("Enter the investment amount: \n");
 scanf("%d", &invest);
 printf("Enter the annual interest rate: \n");
 scanf("%f", &procent);
 printf("Enter the amount of interest per year: \n");
 scanf("%d", &procyear);
 printf("Enter the time of investing money (in years): \n"); 
 scanf("%i", &time); 

 procent /= 100.0;
 
 float a = invest * pow(1 + procent/procyear, procyear*time);

 printf("Your investment result: \n"); 
 printf("Invested amount: %i\n", invest); 
 printf("Total amount of investment: %.2f\n", a); 
 printf("Amount of earnings: %.2f", (a - invest)); 

 return 0; 
}
#include <stdio.h> 
#include <math.h> 

int main() {
	int inv;
	printf("Enter the investment amount: \n");
	scanf("%i", &inv);
	float proc;
	printf("Enter the annual interest rate: \n");
	scanf("%f", &proc);
	proc /= 100.0;
	int nump;
	printf("Enter the amount of interest per year: \n");
	scanf("%i", &nump);
	int time;
	printf("Enter the time of investing money (in years): \n");
	scanf("%i", &time);
	float a = 1 + proc / nump;
	float A = inv * pow(a, time * nump); //pow -підняття до степення 
	A = round(A * 100) / 100; //round -округлення 

	printf("Your investment result: \n");
	printf("Invested amount: %i\n", inv);
	printf("Total amount of investment: %.2f\n", A);
	printf("Amount of earnings: %.2f", (A - inv));




	return 0;
}
#include <stdio.h>
#include <math.h>
#include <string>


int getUserInputInt(std::string inputMessage="")
{
	int userInput;
	printf("%s", inputMessage.c_str());
	scanf("%d", &userInput);
	return userInput;
}


double getUserInputDouble(std::string inputMessage="")
{
	double userInput;
	printf("%s", inputMessage.c_str());
	scanf("%lf", &userInput);
	return userInput;
}


int main()
{
    double principal, rate, amount, profit;
    int time, n;

	// data input
	principal = getUserInputDouble("Enter the principal amount (initial deposit): ");
	rate = getUserInputDouble("Enter the annual interest rate (using decimals like 0.1 instead of 10%): ");
	time = getUserInputInt("Enter the investment time (in years): ");
	n = getUserInputInt("Provide the amount of interest charges per year (available options: 1 / 4 / 12): ");
	while (n != 1 && n != 4 && n != 12) {
		printf("\nWrong input value. Try again\n");
		n = getUserInputInt("Provide the amount of interest charges per year (options: 1 / 4 / 12): ");
	}

    // calculations
	amount = principal * pow((1 + rate / n), n * time);
	profit = amount - principal;

    // results output
    printf("\n--- Investment Summary ---\n");
    printf("Your principal amount: %.2f\n", principal);
    printf("Chosen annual interest rate: %.2f (or %d%%)\n", rate, static_cast<int>(rate*100));
	printf("Total investment time: %d years\n", time);
    printf("Number of interest charges per year: %d\n", n);

    printf("Your deposit after %d years is %.2f\n", time, amount);
    printf("Total profit is %.2f\n", profit);

	return 0;
}

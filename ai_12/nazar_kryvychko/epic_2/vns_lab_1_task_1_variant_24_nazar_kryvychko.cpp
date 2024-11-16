g#include<iostream>
#include<math.h>
int main(void)
{
	//For float
	// (a + b)^3 - a^3 / 3ab^2 + b^3 + 3a^2b
	float a = 1000, b = 0.0001;
	float upperPart = (pow((a + b), 3) - pow(a, 3));
	float lowerPart = (3 * a * pow(b, 2) + pow(b, 3) + 3 * pow(a, 2) * b);
	float result = upperPart / lowerPart;

	//For double

	double aD = 1000, bD = 0.0001;
	double upperPartD = (pow((aD + bD), 3) - pow(aD, 3));
	double lowerPartD = (3 * aD * pow(bD, 2) + pow(bD, 3) + 3 * pow(aD, 2) * bD);
	double resultD = upperPartD / lowerPartD;

	std::cout << "For float: " << result << std::endl
		<< "For double: " << resultD << std::endl;


	return 0;
}
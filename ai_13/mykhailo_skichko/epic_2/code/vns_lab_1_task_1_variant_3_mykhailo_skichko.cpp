#include <iostream>
#include <cmath>

int main()
{
	float a_float = 1000.0f, b_float = 0.0001f;
	double a_double = 1000.0, b_double = 0.0001;

	float numerator_float = pow(a_float + b_float, 3) - (pow(a_float, 3) + 3 * pow(a_float, 2) * b_float);
	float denominator_float = 3 * a_float * pow(b_float, 2) + pow(b_float, 3);
	float result_float = numerator_float / denominator_float;

	double numerator_double = pow(a_double + b_double, 3) - (pow(a_double, 3) + 3 * pow(a_double, 2) * b_double);
	double denominator_double = 3 * a_double * pow(b_double, 2) + pow(b_double, 3);
	double result_double = numerator_double / denominator_double;

	std::cout << "Using float: " << result_float << std::endl;
	std::cout << "Using double: " << result_double << std::endl;

	if (result_float != result_double)
	{
		std::cout << "Difference due to precision errors in floating-point arithmetic." << std::endl;
	}

	return 0;
}

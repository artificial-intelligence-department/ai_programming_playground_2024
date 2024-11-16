#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float a_f = 1000.0f, b_f = 0.0001f;
	double a_d = 1000.0, b_d = 0.0001;

	float numerator_f = 3 * a_f * pow(b_f, 2) + pow(b_f, 3);
	float denominator_f = 3 * a_f * pow(b_f, 2) + pow(b_f, 3);
	float result_f = numerator_f / denominator_f;

	double numerator_d = 3 * a_d * pow(b_d, 2) + pow(b_d, 3);
	double denominator_d = 3 * a_d * pow(b_d, 2) + pow(b_d, 3);
	double result_d = numerator_d / denominator_d;


	cout << "Float : " << result_f << endl;
	cout << "Double : " << result_d << endl;



	return 0;
}

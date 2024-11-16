#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  float a_float = 1000.0f , b_float = 0.0001f;
  double a_double = 1000.0 , b_double = 0.0001;
  
  //float 
  float numerator_float = pow(a_float + b_float,3) - pow(a_float, 3);
  float denominator_float = 3*a_float*pow(b_float, 3) + pow(b_float , 3) + 3*pow(a_float,2)*b_float;
  float result_float = numerator_float/denominator_float;

  //double
  double numerator_double = pow(a_double + b_double, 3) - pow(a_double, 3);
  double denominator_double = 3*a_double*pow(b_double, 3) + pow(b_double, 3) + 3*pow(a_double, 2)*b_double;
  double result_double = numerator_double / denominator_double;

  cout << "result for float : " << result_float << endl;
  cout << "result for double : " << result_double << endl;
  return 0;
}
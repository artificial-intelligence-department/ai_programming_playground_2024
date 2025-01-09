#include <iostream>
#include <cmath>

using namespace std;

int main() {

  const double a = 0.5;
  const double b = 3.1;
  const double x = 1.4;

  double alpha = sqrt(abs ((a * pow(x, 2) * sin(2 * x)) + (exp(-2 * x) * (x + b))) );
  double omega = 1 / pow(cos(x * x * x), 2) - x / pow(a * a + b * b, 1.0 / 3);

  cout << "alpha = " << alpha << endl;
  cout << "omega = " << omega << endl;

  return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

double z(double x, double y, double a, double b) {
  if (x * y > 0) {
    return log(sqrt(a * x * x + b * y * y));
  } else {
    return pow(a, x) + pow(b, y);
  }
}

int main() {
  double a = 1.7;
  double b = 2.3;
  double hx = 0.9;
  double hy = 1;

  for (double x = -1; x <= 1; x += hx) {
    for (double y = -2; y <= 2; y += hy) {
      cout << "x = " << x << ", y = " << y << ", z = " << z(x, y, a, b) << endl;
    }
  }

  return 0;
}
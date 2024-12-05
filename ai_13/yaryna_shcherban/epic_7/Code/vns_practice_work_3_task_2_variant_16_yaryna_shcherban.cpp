#include <iostream>
#define pi 3.14159265

using namespace std;

int main() {

  double r1, r2, h;

  cout << "Enter the radius of the cylinder: ";
  cin >> r1;
  cout << "Enter the radius of the hole: ";
  cin >> r2;
  cout << "Enter the height of the cylinder: ";
  cin >> h;

  double volume = pi * h * (r1 * r1 - r2 * r2);

  cout << "The volume of the cylinder is: " << volume << endl;
  return 0;
}
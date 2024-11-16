#include <iostream>
#include <complex>

using namespace std;

double subtraction_of_real_numbers(double n1, double n2, double n3)
{
   return n1 - n2 - n3;
}

double subtraction_of_real_numbers(double n1, double n2, double n3, double n4, double n5)
{
   return n1 - n2 - n3 - n4 - n5;
}

complex<int> subtraction_of_complex_numbers(complex<int> c1, complex<int> c2)
{
   return c1 - c2;
}

complex<int> subtraction_of_complex_numbers(complex<int> c1, complex<int> c2, complex<int> c3, complex<int> c4)
{
   return c1 - c2 - c3 - c4;
}

int main()
{

   cout << subtraction_of_real_numbers(1, 4, 9) << endl;
   cout << subtraction_of_real_numbers(7, -8, 5, 67, 0) << endl;

   cout << subtraction_of_complex_numbers(complex<int>(1, 2), complex<int>(2, 3)) << endl;
   cout << subtraction_of_complex_numbers(complex<int>(1, 9), complex<int>(7, 6), complex<int>(-6, 7), complex<int>(0, 4)) << endl;

   return 0;
}
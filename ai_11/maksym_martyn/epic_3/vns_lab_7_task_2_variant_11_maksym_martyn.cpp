#include <iostream>
using namespace std;

double multiply (double a , double b){
  return a*b;
}

int gcd (int a, int b){
  if (b==0){
    return a;
  }
  else {
    return gcd(b,a%b);
  }
}

void multiply (int n1 , int d1 , int n2, int d2 , int& result_numerator , int& result_denominator){
  result_numerator = n1 * n2;
  result_denominator = d1 * d2;

  int gcd_value = gcd(result_numerator, result_denominator);
  result_numerator /= gcd_value;
  result_denominator /= gcd_value;
}
int main (){
  double decimal_result = multiply(3.1 , 1.6);
  cout << "Multiplication of 3.1 and 1.6 = " << decimal_result << endl;

  int numerator1 = 4; int denominator1 = 5;
  int numerator2 = 8; int denominator2 = 9;

  int result_numerator , result_denominator;
  multiply (numerator1 ,denominator1 ,numerator2,denominator2,result_numerator,result_denominator);
  cout << "Multiplication of ordinary fractions 4/5 and 8/9 = " << result_numerator << '/' << result_denominator;
  return 0;
}
//використав перевантаження функції та рекурсію
#include <iostream>
#include <cmath>
using namespace std;

int factorial (int n){
  int result = 1;
  for (int i = 2; i <= n; i++)
  {
    result *= i;
  }
  return result;
}

int main(){
  int n;
  double sum = 0;
  cout << "n = ";
  cin >> n;
  sum = factorial(n)/pow(n , n);
  printf("Sum = %.4lf" , sum);
  
  return 0;
}
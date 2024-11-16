#include <iostream>
#include <cstdarg>
using namespace std;

// Пошук найбільшого спільного дільника (використ. рекурс. функ.)
int gcd (int a, int b){
  if (b==0){
    return a;
  }
  else {
    return gcd(b,a%b);
  }
}

void sum (int count , ...){
  long long total_numerator = 0;
  long long common_denominator = 1;

  va_list args;         // Для змінної кількості параметрів 
  va_start(args,count); // зберігає адреси всіх аргументів після count

  for (int i = 0; i < count; i++){
    int numerator = va_arg (args,int);
    int denominator = va_arg(args , int);
    common_denominator *= denominator; // <--
  }
  va_start (args, count); // restart

  for (int i = 0; i< count;i++) {
    int numerator = va_arg (args,int);
    int denominator = va_arg(args , int);
    total_numerator += numerator * (common_denominator/denominator);
  }
  va_end(args);
  
  int gcd_value = gcd (total_numerator,common_denominator);
  total_numerator /= gcd_value;
  common_denominator /= gcd_value;
  cout << total_numerator << "/" << common_denominator << endl;
}

int main (){
  cout << "Sum for 5 fractions: ";
  sum (5, 1, 2, 1, 3, 1, 4, 1, 5, 1, 6);

  cout << "Sum for 10 fractions: ";
  sum(10, 1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9, 1, 10, 1, 11);

  cout << "Sum for 12 fractions: ";
  sum(12, 1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9, 1, 10, 1, 11, 1, 12, 1, 13);

  return 0;
}
// використав Цикли, Функції, Функції зі змінною кількістю параметрів (еліпсис), Рекурсія та Вбудовані функції
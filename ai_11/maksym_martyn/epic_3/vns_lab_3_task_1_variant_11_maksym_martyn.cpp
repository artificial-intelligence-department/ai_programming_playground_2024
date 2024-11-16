#include <iostream>
#include <cmath>
using namespace std;

double exactFunction(double x){
  return (1 + 2 * pow(x, 2)) * exp(pow(x, 2));
}

int factorial (int n){
  int result = 1;
  for (int i = 2; i <= n; i++)
  {
    result *= i;
  }
  return result;
}

// Функція для обчислення значення ряду для заданого числа членів n
double sumForN(double x , int n){
  double sum = 0;
  for (int k = 0; k < n; k++)
  {
    double An = (1 + 2 * pow(x, 2)) * pow(pow(x, 2), k) / factorial(k); 
    sum += An;
  }
  return sum;
}

// Функція для обчислення значення ряду для заданої точності e
//Цей цикл додає члени ряду, поки вони значно впливають на результат. 
double sumForE(double x ,double e){
  double sum = 0;
  double An;
  int k = 0;
  while (true){
  An = (1 + 2 * pow(x, 2)) * pow(pow(x, 2), k) / factorial(k); // Степеневий Ряд Тейлора e^(x^2)=1+ ( x^2/1! )​ + (x^4​/2!) + ...
  if (abs(An) > e){ // abs - модуль , використовується для перевірки абсолютного значення змінної An
    sum += An;
    k++;
  }
  else{
    break;
  }
  return sum;
}
  
}
int main(){
  double a = 0.1, b = 1.0 , e = 0.0001;
  int k = 10 , n = 10;
  double step = (b-a)/k;

  for (double x = a; x < b; x+=step){
    double exact = exactFunction(x);
    double seriesN = sumForN(x, n);
    double seriesE = sumForE(x, e);

    cout << "X=" << x << "\tSN=" << seriesN << "\tSE=" << seriesE << "\tY=" << exact << endl;
    //Тут X- значення параметра; SN- значення суми для заданого n; SE- значення суми для заданої точності; Y-точне значення функції.
  }
  return 0;
}
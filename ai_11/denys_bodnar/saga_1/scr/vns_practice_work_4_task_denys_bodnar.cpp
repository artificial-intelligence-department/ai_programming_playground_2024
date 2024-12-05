#include <iostream>

using namespace std;

int main() {
  int n;
  cout << "Введіть n: ";
  cin >> n;

  double suma = 1;
  for (int i = 2; i <= n; i++) {
    suma += 1.0 / i;
  }

  cout << "Сума перших " << n << " членів ряду: " << suma << endl;

  return 0;
}
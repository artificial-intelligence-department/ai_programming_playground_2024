#include <iostream>
#include <cmath>

using namespace std;

// Функція для обчислення факторіалу
double factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    double epsilon = 0.0001;
    double suma = 0.0;
    double element;
    int n = 0;

    do {
        element = pow(10, n) / factorial(n);
        suma += element;
        n++;
    } while (element >= epsilon);

    cout << "Сума ряду з точністю ε = 0.0001: " << suma << endl;

    return 0;
}

#include <iostream>
#include <complex> 

using namespace std;

// Перевантажена функція для множення дійсних чисел
double multiply(double a, double b) {
    return a * b;
}

// Перевантажена функція для множення комплексних чисел
complex<double> multiply(complex<double> a, complex<double> b) {
    return a * b;
}

int main() {
    // Множення дійсних чисел
    double real1 = 3.5, real2 = 2.0;
    cout << "Множення дійсних чисел: " << real1 << " * " << real2 << " = " << multiply(real1, real2) << endl;

    // Множення комплексних чисел
    complex<double> complex1(3.0, 4.0); // Комплексне число 3 + 4i
    complex<double> complex2(1.0, 2.0); // Комплексне число 1 + 2i

    // Обчислення результату множення
    complex<double> complex_result = multiply(complex1, complex2);

    // Отримання дійсної та уявної частин для введених комплексних чисел
    double x1 = complex1.real();
    double y1 = complex1.imag();
    double x2 = complex2.real();
    double y2 = complex2.imag();

    // Отримання дійсної та уявної частин результату
    double x3 = complex_result.real();
    double y3 = complex_result.imag();

    // Виведення результатів
    cout << "Множення комплексних чисел: (" << x1 << " + " << y1 << "i) * (" 
         << x2 << " + " << y2 << "i) = " << x3 << " + " << y3 << "i" << endl;

    return 0;
}


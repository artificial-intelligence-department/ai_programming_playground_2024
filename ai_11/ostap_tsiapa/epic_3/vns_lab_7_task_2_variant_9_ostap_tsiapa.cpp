#include <iostream>

using namespace std;

// Структура для звичайних дробів
struct drib {
    int numerator;   // Чисельник
    int denominator; // Знаменник
};

// Функція для знаходження найбільшого спільного дільника
int nsd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Спрощення дробу
drib simplify(drib frac) {
    int common = nsd(frac.numerator, frac.denominator);
    frac.numerator /= common;
    frac.denominator /= common;
    return frac;
}

// Перевантажена функція для додавання десяткових дробів
double add(double a, double b) {
    return a + b;
}

// Перевантажена функція для додавання звичайних дробів
drib add(drib f1, drib f2) {
    drib result;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    return simplify(result);
}

int main() {
    // Виклик функції додавання десяткових дробів
    double dec1 = 3.5;
    double dec2 = 2.3;
    double decResult = add(dec1, dec2);
    cout << "Додавання десяткових дробів: " << dec1 << " + " << dec2 << " = " << decResult << endl;

    // Виклик функції додавання звичайних дробів
    drib frac1 = {3, 4};
    drib frac2 = {2, 5};
    drib fracResult = add(frac1, frac2);
    cout << "Додавання звичайних дробів: " << frac1.numerator << "/" << frac1.denominator 
         << " + " << frac2.numerator << "/" << frac2.denominator 
         << " = " << fracResult.numerator << "/" << fracResult.denominator << endl;

    return 0;
}

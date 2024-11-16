#include <iostream>  
using namespace std;


double add(double a, double b) {
    return a + b;
}


struct Fraction {
    int numerator;  
    int denominator;

    
    void simplify() {
        int gcd = findGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

   
    static int findGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};


Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    result.simplify();  
    return result;
}

int main() {
    
    double num1, num2;
    cout << "Введіть два десяткових дроби: ";
    cin >> num1 >> num2;
    cout << "Сума десяткових дробів: " << add(num1, num2) << endl;

   
    Fraction frac1, frac2;
    cout << "Введіть чисельник і знаменник першого звичайного дробу: ";
    cin >> frac1.numerator >> frac1.denominator;
    cout << "Введіть чисельник і знаменник другого звичайного дробу: ";
    cin >> frac2.numerator >> frac2.denominator;

    Fraction result = add(frac1, frac2);
    cout << "Сума звичайних дробів: " << result.numerator << "/" << result.denominator << endl;

    return 0;  
}

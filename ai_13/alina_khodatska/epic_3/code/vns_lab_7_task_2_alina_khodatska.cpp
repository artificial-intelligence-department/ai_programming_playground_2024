#include <iostream>

// ������������� ������� ��� ������ ���������� �����
double divide(double a, double b) {
    if (b == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        return 0;
    }
    return a / b;
}

// ��������� ��� ��������� �����
struct Fraction {
    int numerator;   // ���������
    int denominator; // ���������

    // ����������� ��� ����������� �����
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (den == 0) {
            std::cerr << "Error: Division by zero!" << std::endl;
            numerator = 0;
            denominator = 1; // �� �������������
        }
    }

    // �������������� ��������� ������ ��� ��������� �����
    Fraction operator/(const Fraction& other) {
        if (other.numerator == 0) {
            std::cerr << "Error: Division by zero!" << std::endl;
            return Fraction(0, 1); // ��������� ������������ ���
        }
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Fraction(num, den);
    }

    // ������� ��� ��������� �����
    void print() const {
        std::cout << numerator << "/" << denominator << std::endl;
    }

    // ������� ��� ������������ ����� � ���������� ���
    double toDecimal() const {
        return static_cast<double>(numerator) / denominator;
    }
};

int main() {
    // ������ ������������� ������� ��� ������ ���������� �����
    double a = 15.5, b = 5.0;
    double result_decimal = divide(a, b);
    std::cout << "Result of decimal division: " << result_decimal << std::endl;

    // ������ ��������������� ��������� ��� ������ ��������� �����
    Fraction f1(3, 4); // 3/4
    Fraction f2(2, 5); // 2/5

    std::cout << "Result of fraction division: ";
    Fraction result_fraction = f1 / f2;
    result_fraction.print(); // ��������� ���������� ������ ��������� �����

    // �������� ��������� � ������ ����������� �����
    std::cout << "Decimal result of fraction division: " << result_fraction.toDecimal() << std::endl;

    return 0;
}

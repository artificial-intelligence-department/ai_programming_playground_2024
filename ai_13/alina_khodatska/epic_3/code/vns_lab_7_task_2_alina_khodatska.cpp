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
    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            std::cerr << "Error: Division by zero!" << std::endl;
            return Fraction(0, 1); // ��������� ������������ ���
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    // ������������ ����� � ���������� ���
    double toDecimal() const {
        return static_cast<double>(numerator) / denominator;
    }
};

int main() {
    // ������ ������������� ������� ��� ������ ���������� �����
    double a = 15.5, b = 5.0;
    std::cout << "Result of decimal division: " << divide(a, b) << std::endl;

    // ������ ��������������� ��������� ��� ������ ��������� �����
    Fraction f1(3, 4); // 3/4
    Fraction f2(2, 5); // 2/5
    Fraction result_fraction = f1 / f2;  // ��������� ������ ��������� �����

    std::cout << "Result of fraction division: " << result_fraction.numerator << "/" << result_fraction.denominator << std::endl;
    std::cout << "Decimal result of fraction division: " << result_fraction.toDecimal() << std::endl;

    return 0;
}

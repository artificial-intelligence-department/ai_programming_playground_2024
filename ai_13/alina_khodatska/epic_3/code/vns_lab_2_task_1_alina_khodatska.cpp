#include <iostream>
#include <cmath>

// ������� ��� ���������� ��������� �����
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// ������� ��� ���������� n-�� ����� ����
double computeTerm(int n) {
    return (pow(2, n) * factorial(n)) / pow(n, n);
}

int main() {
    const double epsilon = 0.0001; // �������
    double sum = 0.0; // ���� ����
    double term; // �������� ���� ����
    int n = 1; // ������ ����� ����

    // ���� ��� ���������� ���� ����, ���� ���� �� ����� ������ �� epsilon
    do {
        term = computeTerm(n);
        sum += term;
        ++n;
    } while (std::abs(term) >= epsilon);

    // ��������� ���������� � ��������� ����������
    std::cout << "Row sum with accuracy epsilon = " << epsilon << " equals: " << sum << std::endl;

    return 0;
}

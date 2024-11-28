#include <iostream>
#include <cmath>

// ���������� ������� ��� ���������� ��������� �����
unsigned long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);  // ����������� ������
}

// ������� ��� ���������� n-�� ����� ����
double computeTerm(int n) {
    return (pow(2, n) * factorial(n)) / pow(n, n);  // ���������� �������� n-�� ����� ����
}

int main() {
    const double epsilon = 0.0001; // �������
    double sum = 0.0; // ���� ����
    double term; // �������� ���� ����
    int n = 1; // ������ ����� ����

    // ���� do while ��� ���������� ���� ����
    do {
        term = computeTerm(n);
        sum += term;
        ++n;
    } while (std::abs(term) >= epsilon);

    std::cout << "Row sum with accuracy epsilon = " << epsilon << " equals: " << sum << std::endl;

    return 0;  // ���������� 0
}

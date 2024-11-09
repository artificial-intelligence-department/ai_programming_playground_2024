#include <iostream>
#include <cmath> 

int main() {
    int m = 5, n = 3;

    // 1) m + --n
    int result1 = m + --n;
    std::cout << "Result of m + --n: " << result1 << " (m=" << m << ", n=" << n << ")" << std::endl;

    m = 5;
    n = 3;

    // 2) m++ < ++n
    bool result2 = m++ < ++n;
    std::cout << "Result of m++ < ++n: " << (result2 ? "true" : "false") << " (m=" << m << ", n=" << n << ")" << std::endl;

    m = 5;
    n = 3;

    // 3) n-- < --m
    bool result3 = n-- < --m;
    std::cout << "Result of n-- < --m: " << (result3 ? "true" : "false") << " (m=" << m << ", n=" << n << ")" << std::endl;

    //���������:
    //1) �����'m + --n'�������� �������'n', � ���� ���� ���� ��'m'.
    //2) �����'m++ < + + n'�������� ������'n', � ���� ������� � ��������'m', � ���� ������'m'.
    //3) �����'n-- < -m'������'m', � ���� ������� � ��������'n', � ���� ������'n'.

    return 0;
}

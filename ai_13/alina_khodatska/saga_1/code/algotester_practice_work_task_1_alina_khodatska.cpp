#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    std::string minNumber = s;
    std::string maxNumber = s;

    // ���������� ���������� �����
    for (size_t i = 0; i < s.size(); ++i) {
        if (minNumber[i] == '*') {
            if (i == 0) {
                minNumber[i] = '1'; // ������ ������ �� ���� ���� 0
            }
            else {
                minNumber[i] = '0';
            }
        }
    }

    // ���������� ������������� �����
    for (size_t i = 0; i < s.size(); ++i) {
        if (maxNumber[i] == '*') {
            maxNumber[i] = '9';
        }
    }

    // ��������� ����������
    std::cout << minNumber << " " << maxNumber << std::endl;

    return 0;
}

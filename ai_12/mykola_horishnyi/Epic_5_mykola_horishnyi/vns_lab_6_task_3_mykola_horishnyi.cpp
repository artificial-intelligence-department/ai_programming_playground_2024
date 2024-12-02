#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
    char s[256];  // ����� ��� ���������� �����
    cout << "������ �����: ";  // ����������� ��� �����������
    fgets(s, sizeof(s), stdin);  // ������� ����� (�� ����� 255 �������)

    // ��������� �������� ������ ������ �����, ���� ���� ���� �������� fgets
    s[strcspn(s, "\n")] = 0;

    // ��������� ����� �� �����
    char* word = strtok(s, " ");  // ��������� �� �������

    cout << "����� � ���� ������:" << endl;
    while (word != nullptr) {
        int digitCount = 0;  // ˳������� ���� � ����

        // ���������� ����� ������ �����
        for (int i = 0; word[i] != '\0'; i++) {
            if (isdigit(word[i])) {  // ���� ������ � ������
                digitCount++;
            }
        }

        // ���� � ���� ���� ���� �����
        if (digitCount == 1) {
            cout << word << endl;  // �������� �����
        }

        word = strtok(nullptr, " ");  // �������� �������� �����
    }

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main() {
    // ������� ������ ������
    string s;
    cin >> s;

    // ���� ������ ������� (�� ���� �������, ���� ��������� ����������, �� ������� ���� ? 1)
    if (s.empty()) {
        cout << 0 << endl;
        return 0;
    }

    // ����� ��� ��������� ���������� �������
    string compressed = "";

    int n = s.size();
    int i = 0;

    while (i < n) {
        char currentChar = s[i];
        int count = 1;

        // ϳ�������� ������� ��������� ������� �����
        while (i + 1 < n && s[i + 1] == currentChar) {
            count++;
            i++;
        }

        // ��������� ������� �� ������� ������� (���� ����� ������)
        compressed += currentChar;
        if (count > 1) {
            compressed += to_string(count);
        }

        // ���������� �� ���������� �������
        i++;
    }

    // ��������� ����������
    cout << compressed << endl;

    return 0;
}

//aaabbcddd

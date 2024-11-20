#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int* a = new int[n];  // �������� �������� ���'��
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_len = 0; // ����������� ������� ������� � ������������ ������
    int current_len = 0; // ������� ������� �������

    for (int i = 0; i < n; i++) {
        if (a[i] >= k) { // ���� ��� �����������
            current_len++;
        }
        else {
            max_len = max(max_len, current_len); // ��������� ����������� �������
            current_len = 0; // ������� ������� �������
        }
    }

    // ������� ������� ������� ���� ���� ���������, ���������� ���� �� ���
    max_len = max(max_len, current_len);

    cout << max_len << endl;

    delete[] a;  // �� �������� �������� ���'���

    return 0;
}

// 10 5
// 1 2 3 5 6 7 4 8 9 10

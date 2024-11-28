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

    // ��������� ���� ��� �������� ��� �������
    for (int i = 0; i < n; i++) {
        int current_len = 0;
        for (int j = i; j < n; j++) {
            if (a[j] >= k) { // ���� ��� �����������
                current_len++;
            }
            else {
                break; // ���� �������� �������, ���� ������ �� k, ���������� �������� ����� �������
            }
        }
        max_len = max(max_len, current_len); // ��������� ����������� ������� �������
    }

    cout << max_len << endl;

    delete[] a;  // ��������� ���'���
    return 0;
}

// ������� ��� �����
// 10 5
// 1 2 3 5 6 7 4 8 9 10


// 10 5
// 1 2 3 5 6 7 4 8 9 10

#include <iostream>
#include <vector>

using namespace std;

// ������� ��� ������ ������������� �������� � ����� ����������� ������
int findMaxInRow(const vector<int>& row) {
    int maxElem = row[0];
    for (int i = 1; i < row.size(); i++) {
        if (row[i] > maxElem) {
            maxElem = row[i];
        }
    }
    return maxElem;
}

// ������� ��� ��������� ����� �������� ����� ������
void cyclicShiftRight(vector<int>& row, int shift) {
    int n = row.size();
    // ���� ���� ������ �� ������� ��������, �������� ����
    shift = shift % n;
    vector<int> temp(n);

    // ������� �������� � ����� ����� � �������� ������
    for (int i = 0; i < n; i++) {
        temp[(i + shift) % n] = row[i];
    }

    // ���������� �������� � ����������� ������ ����� � ����������� �����
    for (int i = 0; i < n; i++) {
        row[i] = temp[i];
    }
}

// ������� �������
int main() {
    // ��������� ���������� �����
    int rows = 3, cols = 5;  // ������� ����� � �������� (����� ������)
    vector<vector<int>> arr(rows, vector<int>(cols));

    // ����������� ������ ����������� �������
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100;  // ���������� �������� ����������� ������� �� 0 �� 99
        }
    }

    // ��������� ����������� ������
    cout << "Initial 2D array: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // ��� ������� ����� ������ ��������� ������������ ������� � ������ �������� ����
    for (int i = 0; i < rows; i++) {
        int maxElem = findMaxInRow(arr[i]);  // ������ ������������ ������� � �����
        cout << "Max element in row " << i + 1 << ": " << maxElem << endl;

        cyclicShiftRight(arr[i], maxElem);  // ������� ����� ������ �� maxElem
    }

    // ��������� �������� ������
    cout << "Modified 2D array after cyclic shifts: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

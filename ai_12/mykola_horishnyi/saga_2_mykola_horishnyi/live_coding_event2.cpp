#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip> // ��� ������������ ������

using namespace std;

// ������� ��� ��������� �������������� �����������
void generateUserID(const string& name, float userID[5][3]) {
    // ���������� ���� ���� �� ����������
    string sortedName = name;
    sort(sortedName.begin(), sortedName.end());

    // ���������� ������������ ������ �� ����� ASCII ������� * 0.4
    int asciiValues[100];
    int n = sortedName.length();
    for (int i = 0; i < n; ++i) {
        asciiValues[i] = static_cast<int>(sortedName[i]) * 0.4;
    }

    // �������� ���� �������� � ��������� 1, 2, 3
    int filteredValues[3] = { 0 };
    for (int i = 1; i <= 3 && i < n; ++i) {
        filteredValues[i - 1] = asciiValues[i];
    }

    // ��������� ����������� ������ 5x3
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (j < 3) {
                userID[i][j] = static_cast<float>(filteredValues[j]);
            }
            else {
                userID[i][j] = static_cast<float>(i + j) * 1.1f; // ���������� ����� �������
            }
        }
    }
}

// ������� ��� ������������ ���� �������
void multiplyMatrices(float mat1[5][3], float mat2[3][3], float result[5][3]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i][j] = 0.0f;
            for (int k = 0; k < 3; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// ������� ��� ������ �������
void printMatrix(float matrix[5][3]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << fixed << setprecision(2) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    string name;
    cout << "Enter your name: ";
    cin >> name;

    // ��������� �������������� �����������
    float userID[5][3];
    generateUserID(name, userID);

    cout << "\nGenerated User ID Matrix:\n";
    printMatrix(userID);

    // ��� ������������: ������������ ������� �� ���� ����
    float resultMatrix[5][3];
    multiplyMatrices(userID, userID, resultMatrix);

    cout << "\nResulting Matrix after Multiplication:\n";
    printMatrix(resultMatrix);

    return 0;
}

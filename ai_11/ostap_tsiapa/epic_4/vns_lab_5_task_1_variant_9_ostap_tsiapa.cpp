#include <iostream>
#include <vector>
using namespace std;

// Функція для обчислення суми елементів нижче головної діагоналі
int suma_pid_diag(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    int suma = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            suma += matrix[i][j];
        }
    }
    return suma;
}

int main() {
    int n;
    cout << "Введіть розмір квадратної матриці: ";
    cin >> n;

    int numMatrices;
    cout << "Введіть кількість матриць: ";
    cin >> numMatrices;

    vector<vector<vector<int>>> matrices(numMatrices, vector<vector<int>>(n, vector<int>(n)));

    // Введення матриць
    for (int k = 0; k < numMatrices; ++k) {
        cout << "Введіть елементи матриці " << k + 1 << ":\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> matrices[k][i][j];
            }
        }
    }

    // Знаходження максимальної суми
    int maxSuma = INT_MIN;
    for (int k = 0; k < numMatrices; ++k) {
        int currentSuma = suma_pid_diag(matrices[k]);
        if (currentSuma > maxSuma) {
            maxSuma = currentSuma;
        }
    }

    cout << "Максимальна сума елементів, які розташовані нижче головної діагоналі: " << maxSuma << endl;

    return 0;
}

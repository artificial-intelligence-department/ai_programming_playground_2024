#include <iostream>
using namespace std;

int IsMyMatrix(int arr[100][100], int n) {
    int product = 1;
    bool exist = false;

    for (int j = 0; j < n; j++) {
        int FirstNumber = arr[0][j];
        bool IsTruecolum = true;

        // Перевірка першого елемента стовпця
        for (int i = 0; i < n; i++) {
            if (FirstNumber <= arr[i][i] || FirstNumber <= arr[i][n - i - 1]) {
                IsTruecolum = false;
                break;
            }
        }

        // Якщо умова виконується, обчислюємо добуток елементів стовпця
        if (IsTruecolum) {
            exist = true;
            for (int r = 0; r < n; r++) {
                product *= arr[r][j];
            }
        }
    }

    // Повертаємо результат
    return exist ? product : 0;
}

int main() {
    int n;

    cout << "Enter the size of the matrix (n*n): ";
    cin >> n;
    cout << "Enter the elements of the matrix:" << endl;
    int arr[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int result = IsMyMatrix(arr, n);
    if (result != 0) {
        cout << result << " is your answer" << endl;
    } else {
        cout << "There's no such columns" << endl;
    }

    return 0;
}

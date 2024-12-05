#include <iostream>
using namespace std;

int IsMyMatrix(int arr[100][100], int n) {
    int product = 1;
    bool exist = false;

    for (int j = 0; j < n; j++) {
        int FirstNumber = arr[0][j];
        bool IsTruecolum = true;

        for (int i = 0; i < n; i++) {
            if (FirstNumber <= arr[i][i] || FirstNumber <= arr[i][n - i - 1]) {
                IsTruecolum = false;
                break;
            }
        }
        
        if (IsTruecolum) {
            exist = true;
            for (int r = 0; r < n; r++) {
                product *= arr[r][j];
            }
        }
    }

    return exist ? product : 0;
}

int main() {
    int n;

    cout << "Введіть розмір квадратної матриці: ";
    cin >> n;
    cout << "Введіть елементи матриці" << endl;
    int arr[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int result = IsMyMatrix(arr, n);
    if (result != 0) {
        cout << result << endl;
    } else {
        cout << "Таких стовпців немає" << endl;
    }

    return 0;
}
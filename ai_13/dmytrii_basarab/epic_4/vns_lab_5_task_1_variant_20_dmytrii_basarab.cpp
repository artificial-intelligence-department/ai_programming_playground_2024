#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функція для збору і знаходження унікальних значень
void collect(int arr[100][100], int rows, int cols) {
    vector<int> v;
    vector<int> res;

    // Переносимо елементи з масиву в вектор
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            v.push_back(arr[i][j]);
        }
    }

    sort(v.begin(), v.end());

    // Знаходимо числа що не мають повторів
    for (int l = 0; l < v.size(); l++) {//масив відсортований повторювані елементи один біля одного
        if ((l == 0 || v[l] != v[l - 1]) && (l == v.size() - 1 || v[l] != v[l + 1])) {
            res.push_back(v[l]);
        }
    }

    
    if (res.empty()) {
        cout << "Немає унікальних чисел!" << endl;
    } else {
        cout << "Мінімальне число без повторів: " << *min_element(res.begin(), res.end()) << endl;
    }
}

int main() {
    int rows, cols;

  
    cout << "Введіть кількість рядків: ";
    cin >> rows;
    cout << "Введіть кількість стовпців: ";
    cin >> cols;

    int arr[100][100];  


    cout << "Введіть елементи масиву:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    // Викликаємо функцію для знаходження унікальних чисел
    collect(arr, rows, cols);

    return 0;
}

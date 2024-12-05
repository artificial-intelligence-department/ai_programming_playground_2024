#include <iostream>
#include <vector>

using namespace std;

// Функція для пошуку максимального елемента в рядку двовимірного масиву
int findMaxInRow(const vector<int>& row) {
    int maxElem = row[0];
    for (int i = 1; i < row.size(); i++) {
        if (row[i] > maxElem) {
            maxElem = row[i];
        }
    }
    return maxElem;
}

// Функція для циклічного зсуву елементів рядка вправо
void cyclicShiftRight(vector<int>& row, int shift) {
    int n = row.size();
    // Якщо зсув більший за кількість елементів, зменшуємо його
    shift = shift % n;
    vector<int> temp(n);

    // Копіюємо елементи в новий масив з циклічним зсувом
    for (int i = 0; i < n; i++) {
        temp[(i + shift) % n] = row[i];
    }

    // Переносимо елементи з тимчасового масиву назад в оригінальний рядок
    for (int i = 0; i < n; i++) {
        row[i] = temp[i];
    }
}

// Основна функція
int main() {
    // Створюємо двовимірний масив
    int rows = 3, cols = 5;  // кількість рядків і стовпців (можна змінити)
    vector<vector<int>> arr(rows, vector<int>(cols));

    // Ініціалізація масиву випадковими числами
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100;  // Заповнюємо елементи випадковими числами від 0 до 99
        }
    }

    // Виведення початкового масиву
    cout << "Initial 2D array: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Для кожного рядка масиву знаходимо максимальний елемент і робимо циклічний зсув
    for (int i = 0; i < rows; i++) {
        int maxElem = findMaxInRow(arr[i]);  // Знайти максимальний елемент в рядку
        cout << "Max element in row " << i + 1 << ": " << maxElem << endl;

        cyclicShiftRight(arr[i], maxElem);  // Зсунути рядок вправо на maxElem
    }

    // Виведення зміненого масиву
    cout << "Modified 2D array after cyclic shifts: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

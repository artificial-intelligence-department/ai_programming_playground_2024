// var 18
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

// Оголошення структури для зберігання інформації про число
struct NumberInfo {
    double number;
    bool is_positive;
};

// Функція для обчислення середнього арифметичного
double calculateAverage(double arr[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

// Перевантажена функція для обчислення середнього арифметичного в 2D масиві
double calculateAverage(double arr[][5], int rows) {
    double sum = 0.0;
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 5; j++) {
            sum += arr[i][j];
            count++;
        }
    }
    return sum / count;
}

// Рекурсивна функція для обчислення середнього арифметичного
double recursiveAverage(double arr[], int n, int index = 0, double sum = 0.0) {
    if (index == n) return sum / n;
    return recursiveAverage(arr, n, index + 1, sum + arr[index]);
}

int main() {
    int n;
    cout << "Введіть кількість чисел: ";
    cin >> n;

    double* arr = new double[n]; // використання динамічного масиву (вказівник)
    
    for (int i = 0; i < n; i++) {
        cout << "Введіть число " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Середнє арифметичне за допомогою масиву
    double average = calculateAverage(arr, n);
    cout << "Середнє арифметичне (масив): " << average << endl;

    // Запис результату у файл
    ofstream outFile("results.txt");
    if (outFile.is_open()) {
        outFile << "Середнє арифметичне: " << average << endl;
        outFile.close();
    } else {
        cout << "Не вдалося відкрити файл для запису." << endl;
    }

    // Зчитування результату з файлу
    ifstream inFile("results.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Не вдалося відкрити файл для зчитування." << endl;
    }

    // Структура для чисел
    NumberInfo numbers[5];
    for (int i = 0; i < 5; i++) {
        cout << "Введіть число для структури " << i + 1 << ": ";
        cin >> numbers[i].number;
        numbers[i].is_positive = numbers[i].number > 0;
    }

    // Двовимірний масив
    double twoDimensionalArray[3][5];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            twoDimensionalArray[i][j] = i + j;
        }
    }

    // Середнє арифметичне для двовимірного масиву
    double average2D = calculateAverage(twoDimensionalArray, 3);
    cout << "Середнє арифметичне (двовимірний масив): " << average2D << endl;

    // Цикл do-while для введення числа
    double num;
    do {
        cout << "Введіть позитивне число (для завершення введіть 0): ";
        cin >> num;
        if (num < 0) {
            cout << "Число повинно бути позитивним." << endl;
            continue; // Пропускаємо залишок циклу, якщо число від'ємне
        }
        if (num == 0) break; // Вихід з циклу
    } while (true);

    // Очищення динамічно виділеної пам'яті
    delete[] arr;
}

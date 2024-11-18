#include <iostream>
#include <cstdlib>  // Для функцій rand() та srand()
#include <ctime>    // Для функції time()
using namespace std;

// Функція для зсуву масиву циклічно на K елементів вправо
void shiftArray(int arr[], int n, int k) {
    k = k % n; // Для врахування циклічності, якщо k > n
    int element[n];
    for (int i = 0; i < n; ++i) {
        element[(i + k) % n] = arr[i];
    }
    for (int i = 0; i < n; ++i) {
        arr[i] = element[i];
    }
}

int main() {
    const int N = 100;
    int a[N];
    int realLength;

    // Введення реальної довжини масиву
    cout << "Введіть реальну довжину масиву (не більше " << N << "): ";
    cin >> realLength;
    if (realLength > N) {
        cout << "Довжина масиву перевищує максимальне значення." << endl;
        return 1;
    }

    // Ініціалізація генератора випадкових чисел
    srand(static_cast<unsigned>(time(0)));

    // Формування масиву випадкових чисел
    for (int i = 0; i < realLength; ++i) {
        a[i] = rand() % 100; // Випадкові числа від 0 до 99
    }

    // Вивід початкового масиву
    cout << "Початковий масив:" << endl;
    for (int i = 0; i < realLength; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Видалення першого елемента із заданим значенням
    int value;
    cout << "Введіть значення, яке потрібно видалити: ";
    cin >> value;
    int index = -1;
    for (int i = 0; i < realLength; ++i) {
        if (a[i] == value) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < realLength - 1; ++i) {
            a[i] = a[i + 1];
        }
        --realLength;
    } else {
        cout << "Елемент не знайдено." << endl;
    }

    // Зсув масиву циклічно на K елементів вправо
    int k;
    cout << "Введіть кількість елементів для циклічного зсуву вправо: ";
    cin >> k;
    shiftArray(a, realLength, k);

    // Вивід отриманого масиву
    cout << "Отриманий масив після видалення та зсуву:" << endl;
    for (int i = 0; i < realLength; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

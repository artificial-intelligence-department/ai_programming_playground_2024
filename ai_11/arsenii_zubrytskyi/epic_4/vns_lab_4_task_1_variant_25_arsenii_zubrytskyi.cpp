#include <iostream>
#include <algorithm>  // Для std::sort і std::greater
#include <functional> // Для std::greater
using namespace std;

const int N = 100;  // Максимальна кількість елементів масиву
int a[N];           // Масив для зберігання елементів
int n;              // Реальна довжина масиву

// Функція для друку масиву з індексу K до K+1
void printArray(int startIndex, int endIndex) {
    for (int i = startIndex; i <= endIndex && i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void printArrayReverse(int startIndex) {
    for (int i = startIndex; i >= 0; --i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Функція для видалення непарних елементів
void removeOddNumbers() {
    int newIndex = 0;  // Новий індекс для збереження парних елементів
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            a[newIndex++] = a[i];  // Копіюємо парні елементи
        }
    }
    n = newIndex;  // Зменшуємо довжину масиву до кількості парних елементів
}

int main() {
    // Введення довжини масиву
    cout << "Enter the number of elements (up to 100): ";
    cin >> n;

    // Перевірка на коректність введеної довжини
    if (n <= 0 || n > N) {
        cout << "Invalid size!" << endl;
        return 1;
    }

    // Введення елементів масиву
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 1) Перегляд масиву з права наліво (можна переглядати з кінця)
    cout << "Array in reverse order: ";
    printArrayReverse(n - 1);

    // 2) Виведення масиву, починаючи з K-ого елемента до K+1
    int k;
    cout << "Enter the index K to start printing from: ";
    cin >> k;

    // Перевірка коректності введеного індексу
    if (k < 0 || k >= n) {
        cout << "Invalid index K!" << endl;
        return 1;
    }

    cout << "Array from index " << k << " to " << k + 1 << ": ";
    printArray(k, k + 1);

    // 3) Впорядкування елементів по спаданню
    sort(a, a + n, greater<int>());
    cout << "Array sorted in descending order: ";
    printArray(0, n - 1);

    // 4) Знищення непарних елементів
    removeOddNumbers();
    cout << "Array after removing odd elements: ";
    printArray(0, n - 1);

    // 5) Друк масиву з K-ого елемента до K+1 після видалення непарних елементів
    if (k >= n) {
        cout << "Index K is out of range after removing odd elements!" << endl;
    } else {
        cout << "Array from index " << k << " to " << k + 1 << " after removing odd elements: ";
        printArray(k, k + 1);
    }

    return 0;
}

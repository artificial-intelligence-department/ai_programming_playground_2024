#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Крок 1: Створення масиву випадкових чисел
    srand(time(0));  // Ініціалізація генератора випадкових чисел
    int n = 10;  // Розмір масиву (можна змінити)
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;  // Заповнюємо масив випадковими числами від 0 до 99
    }

    // Крок 2: Виведення початкового масиву
    cout << "Step 1: Initial array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Крок 3: Міняємо місцями мінімальний і максимальний елементи
    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    // Міняємо місцями мінімальний і максимальний елементи
    swap(arr[minIndex], arr[maxIndex]);

    // Виводимо масив після зміни мінімального та максимального
    cout << "Step 2: After swapping min and max elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Крок 4: Видаляємо елементи, що перевищують середнє значення на 10%
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    double average = sum / (double)n;
    double threshold = average * 1.1;

    vector<int> filteredArr;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= threshold) {
            filteredArr.push_back(arr[i]);
        }
    }

    // Виводимо масив після видалення елементів, що перевищують середнє на 10%
    cout << "Step 3: After removing elements greater than 10% above average: ";
    for (int i = 0; i < filteredArr.size(); i++) {
        cout << filteredArr[i] << " ";
    }
    cout << endl;

    return 0;
}

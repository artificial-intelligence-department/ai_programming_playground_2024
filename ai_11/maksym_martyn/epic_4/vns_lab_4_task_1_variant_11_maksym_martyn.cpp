// 1) Сформувати одновимірний масив цілих чисел, використовуючи генератор випадкових чисел.
// 2) Знищити 5 перших елементів масиву.
// 3) Додати в кінець масиву 3 нових елементи.
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int initialSize = 10;
    int arr[initialSize];
    int currentSize = initialSize;

    srand(time(0));

    for (int i = 0; i < currentSize; i++) {
        arr[i] = rand() % 100;
    }

    cout << "Initial array: ";
    for (int i = 0; i < currentSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    if (currentSize >= 5) {
        currentSize -= 5;
    }

    const int additionalSize = 3;
    int newArr[initialSize + additionalSize];

    for (int i = 0; i < additionalSize; i++) {
        newArr[i] = (i + 1 < currentSize ? arr[i + 1] : 0) + 2;
    }

    for (int i = 0; i < currentSize; i++) {
        newArr[i + additionalSize] = arr[i];
    }

    currentSize += additionalSize;

    cout << "Array after changes: ";
    for (int i = 0; i < currentSize; i++) {
        cout << newArr[i] << " ";
    }
    cout << endl;

    return 0;
}

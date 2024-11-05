#include <iostream>

using namespace std;

// Функція для друку масиву з К-ого елемента до К+1
void printFromKToKPlus1(int arr[], int size, int K) {
    for (int i = 0; i < size; ++i) {
        cout << arr[(K + i) % size] << " ";
    }
    cout << endl;
}

// Функція для додавання першого і останнього елементів в кільце
void addFirstAndLast(int arr[], int& size) {
    if (size > 0) {
        int first = arr[0];
        int last = arr[size - 1];
        arr[size++] = first;
        arr[size++] = last;
    }
}

// Функція для видалення непарних елементів з кільця
void removeOddElements(int arr[], int& size) {
    int newSize = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            arr[newSize++] = arr[i];
        }
    }
    size = newSize;
}

int main() {
    const int MAX_SIZE = 20;
    int arr[MAX_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    int K = 3;

    // 1) Створення однонаправленого кільця
    // Масив вже є однонаправленим кільцем

    // 2) Друк масиву з К-ого елемента до К+1
    cout << "Initial ring from K to K+1: ";
    printFromKToKPlus1(arr, size, K);

    // 3) Додавання першого і останнього елементів в кільце
    addFirstAndLast(arr, size);
    cout << "Ring after adding first and last elements: ";
    printFromKToKPlus1(arr, size, K);

    // 4) Видалення непарних елементів з кільця
    removeOddElements(arr, size);
    cout << "Ring after removing odd elements: ";
    printFromKToKPlus1(arr, size, K);

    // 5) Друк масиву з К-ого елемента до К+1
    cout << "Final ring from K to K+1: ";
    printFromKToKPlus1(arr, size, K);

    return 0;
}
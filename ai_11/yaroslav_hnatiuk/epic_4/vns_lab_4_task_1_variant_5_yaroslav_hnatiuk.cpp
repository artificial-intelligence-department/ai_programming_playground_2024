#include <iostream>
#include <random>
using namespace std;

int main() {
    int arr[100], size;
    srand(time(nullptr));

    do {
        cout << "Введіть кількість елементів: ";
        cin >> size;
    } while (size > 50);

    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 90) + 10;
    }


    cout << "\nПочатковий масив: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";

    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 7 != 0) {
            arr[newSize++] = arr[i];
        }
    }

    size = newSize;
    cout << endl;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            for(int j = size; j > i; j--) {
                arr[j] = arr[j - 1];
            }
            arr[++i] = 0;
            size++;
        }
    }

    cout << "Кінцевий масив: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";

    return 0;
}

#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    const int N = 100;
    int arr[N];
    int realSize;

    cout << "Введіть реальний розмір масиву (не більше " << N << "): ";
    cin >> realSize;

    if (realSize > N) {
        cout << "Помилка: розмір масиву перевищує допустиме значення!" << endl;
        return 1;
    }

    for (int i = 0; i < realSize; ++i) {
        arr[i] = rand() % 100 + 1;
    }

    cout << "Згенерований масив: ";
    for (int i = 0; i < realSize; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int minValue = *min_element(arr, arr + realSize);

    int newSize = 0;
    for (int i = 0; i < realSize; ++i) {
        if (arr[i] != minValue) {
            arr[newSize++] = arr[i];
        }
    }
    realSize = newSize;

    int sum = accumulate(arr, arr + realSize, 0);
    int averageValue = sum / realSize;

    if (realSize + 3 <= N) {
        for (int i = realSize - 1; i >= 0; --i) {
            arr[i + 3] = arr[i];
        }
        arr[0] = arr[1] = arr[2] = averageValue;
        realSize += 3;
    } else {
        cout << "Помилка: недостатньо місця для додавання елементів!" << endl;
        return 1;
    }

    cout << "Масив над яким виконали всі дії: ";
    for (int i = 0; i < realSize; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
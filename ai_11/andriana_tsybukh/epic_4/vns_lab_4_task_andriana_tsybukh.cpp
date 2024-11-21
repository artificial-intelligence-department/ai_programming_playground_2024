#include <iostream>
#include <algorithm>
#include <numeric> // accumulate
#include <cstdlib> // rand(),  srand()
#include <ctime>   // ініціалізації rand()

using namespace std;


int main() {
    srand(time(0));

    const int SIZE = 100;
    int array[SIZE];
    int realSize;

    cout << "Введіть реальний розмір масиву (не більше " << SIZE << "): ";
    cin >> realSize;
    if (realSize > SIZE) {
        cout << "Розмір масиву перевищує допустиме значення!" << endl;
        return 1;
    }

    // 1) Сформувати одновимірний масив цілих чисел, використовуючи генератор випадкових чисел.
    for (int i = 0; i < realSize; ++i) {
        array[i] = rand() % 100 + 1;
    }

    // 2) Роздрукувати отриманий масив.
    cout << "Згенерований масив: ";
    for (int i = 0; i < realSize; ++i) {
        cout << array[i] << " ";
    }
    cout << "\n";

    // 3) Знищити з масиву всі елементи, які збігаються з його мінімальним значенням.
    int minValue = *min_element(array, array + realSize);

    int newSize = 0;
    for (int i = 0; i < realSize; ++i) {
        if (array[i] != minValue) {
            array[newSize++] = array[i];
        }
    }
    realSize = newSize;

    // 4) Додати на початок масиву 3 елементи зі значенням, яке дорівнює середньому арифметичному масиву.
    int sum = accumulate(array, array + realSize, 0);
    int averageValue = sum / realSize;

    if (realSize + 3 <= SIZE) {
        for (int i = realSize - 1; i >= 0; --i) {
            array[i + 3] = array[i];
        }
        array[0] = array[1] = array[2] = averageValue;
        realSize += 3;
    } else {
        cout << "Недостатньо місця для додавання елементів!" << endl;
        return 1;
    }

    // 5) Роздрукувати отриманий масив
    cout << "Масив над яким виконали всі дії: ";
    for (int i = 0; i < realSize; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;

}
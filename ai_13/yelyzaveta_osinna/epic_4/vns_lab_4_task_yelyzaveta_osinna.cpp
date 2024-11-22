#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Ініціалізуємо генератор випадкових чисел
    srand(time(0));

    // 1. Створення одновимірного динамічного масиву цілих чисел
    const int SIZE = 20; // Початковий розмір масиву
    int* array = new int[SIZE];
    int current_size = SIZE;

    // Заповнення масиву випадковими числами від 0 до 99
    for (int i = 0; i < current_size; ++i) {
        array[i] = rand() % 100;
    }

    // 2. Роздрукувати отриманий масив
    cout << "Початковий масив:" << endl;
    for (int i = 0; i < current_size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    // 3. Видалення елементів, кратних 7
    // Підрахунок кількості елементів, які залишаться
    int new_size = 0;
    for (int i = 0; i < current_size; ++i) {
        if (array[i] % 7 != 0) {
            ++new_size;
        }
    }

    // Створюємо новий масив для збереження елементів, які не є кратними 7
    int* filtered_array = new int[new_size];
    int index = 0;
    for (int i = 0; i < current_size; ++i) {
        if (array[i] % 7 != 0) {
            filtered_array[index++] = array[i];
        }
    }

    // Оновлення розміру і заміна масиву
    delete[] array;
    array = filtered_array;
    current_size = new_size;

    // 4. Додавання 0 після кожного непарного елемента
    // Підрахунок нового розміру масиву з урахуванням вставок
    new_size = current_size;
    for (int i = 0; i < current_size; ++i) {
        if (array[i] % 2 != 0) {
            ++new_size; // Кожен непарний елемент потребує додаткового місця для 0
        }
    }

    // Створення нового масиву для зберігання результату
    int* modified_array = new int[new_size];
    index = 0;
    for (int i = 0; i < current_size; ++i) {
        modified_array[index++] = array[i];
        if (array[i] % 2 != 0) {
            modified_array[index++] = 0; // Додаємо 0 після непарного елемента
        }
    }

    // Оновлення розміру і заміна масиву
    delete[] array;
    array = modified_array;
    current_size = new_size;

    // 5. Роздрукувати отриманий масив
    cout << "Змінений масив:" << endl;
    for (int i = 0; i < current_size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Звільнення пам'яті
    delete[] array;

    return 0;
}

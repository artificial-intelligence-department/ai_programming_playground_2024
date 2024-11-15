#include <iostream>
#include <cstdarg> // Для використання va_list та пов'язаних макросів

using namespace std;

// Функція sum зі змінною кількістю параметрів
int sum(int count, ...) {
    va_list args;
    va_start(args, count); // Ініціалізуємо список аргументів

    int S = 0; // Результуюча сума
    int prev = va_arg(args, int); // Отримуємо перший аргумент як початковий

    // Змінна для визначення знаку чергування (+/-)
    int sign = 1;

    // Проходимо решту аргументів
    for (int i = 1; i < count; i++) {
        int current = va_arg(args, int); // Отримуємо наступний аргумент
        S += sign * (prev * current); // Додаємо або віднімаємо згідно з чергуванням
        sign = -sign; // Змінюємо знак
        prev = current; // Оновлюємо попереднє значення
    }

    va_end(args); // Завершуємо роботу зі списком аргументів
    return S;
}

int main() {
    // Виклики функції sum з різною кількістю параметрів
    cout << "Sum with 5 parameters: " << sum(5, 1, 2, 3, 4, 5) << endl;
    cout << "Sum with 10 parameters: " << sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;
    cout << "Sum with 12 parameters: " << sum(12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) << endl;

    return 0;
}

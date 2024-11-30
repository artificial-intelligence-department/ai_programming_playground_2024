#include<iostream>
using namespace std;

int main() {
    int n; // кількість однокласників
    cin >> n;

    int a[n]; // масив номерів будинків
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int crossings = 0; // кількість переходів через дорогу

    // Початковий бік дороги (парний чи непарний)
    bool isEvenSide = a[0] % 2 == 0;

    // Перебираємо всі будинки і рахуємо переходи
    for (int i = 1; i < n; i++) {
        bool currentIsEven = a[i] % 2 == 0;
        if (currentIsEven != isEvenSide) {
            crossings++; // Перехід через дорогу
        }
        // Оновлюємо бік дороги для наступного будинку
        isEvenSide = currentIsEven;
    }

    // Виводимо кількість переходів
    cout << crossings << endl;

    return 0;
}

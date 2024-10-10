#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<string> drinks;  // Множина для збереження унікальних назв
    string drink;

    // Читання напоїв від Марічки
    for (int i = 0; i < n; i++) {
        cin >> drink;
        drinks.insert(drink);  // Додаємо напої до множини
    }

    // Читання напоїв від Зеника
    for (int i = 0; i < m; i++) {
        cin >> drink;
        drinks.insert(drink);  // Додаємо напої до множини
    }

    // Виведення кількості унікальних напоїв
    cout << drinks.size() << endl;

    return 0;
}

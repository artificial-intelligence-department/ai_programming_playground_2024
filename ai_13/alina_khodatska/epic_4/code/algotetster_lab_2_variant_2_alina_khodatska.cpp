#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Читання входу
    int N;
    cin >> N;
    vector<int> r(N);
    for (int i = 0; i < N; i++) {
        cin >> r[i];
    }

    int a, b, c;
    cin >> a >> b >> c;

    // Крок 1: Видалення елементів a, b, c
    vector<int> newArray;

    // Додаємо всі елементи, які не рівні a, b чи c
    for (int i = 0; i < N; i++) {
        if (r[i] != a && r[i] != b && r[i] != c) {
            newArray.push_back(r[i]);
        }
    }

    // Перевірка на кількість елементів після видалення
    int M = newArray.size();

    if (M < 2) {
        // Якщо елементів після видалення менше ніж 2, то неможливо створити масив сум
        cout << 0 << endl;
        return 0;
    }

    // Крок 2: Створення нового масиву сум
    vector<int> sumArray;
    for (int i = 0; i < M - 1; i++) {
        sumArray.push_back(newArray[i] + newArray[i + 1]);
    }

    // Крок 3: Виведення результату
    cout << sumArray.size() << endl;
    for (int i = 0; i < sumArray.size(); i++) {
        cout << sumArray[i] << " ";
    }
    cout << endl;

    return 0;
}

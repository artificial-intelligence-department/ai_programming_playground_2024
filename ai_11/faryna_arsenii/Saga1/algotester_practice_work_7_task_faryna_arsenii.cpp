#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n; // Кількість компаній
    vector<pair<int, int>> lengths(n); // Вектор пар для довжин і індексів

    // Зчитування довжин офісів
    for (int i = 0; i < n; i++) {
        cin >> lengths[i].first; // Довжина офісу
        lengths[i].second = i + 1; // Зберігаємо індекс (1-based)
    }

    // Сортування пар за довжинами
    sort(lengths.begin(), lengths.end());

    // Виведення порядку індексів
    for (int i = 0; i < n; i++) {
        cout << lengths[i].second << " "; // Виводимо індекси
    }
    cout << endl;

    return 0;
}
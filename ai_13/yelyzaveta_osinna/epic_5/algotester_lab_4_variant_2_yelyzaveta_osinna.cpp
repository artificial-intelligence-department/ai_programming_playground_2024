#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Основна функція
int main() {
    int N;
    cin >> N;

    vector<int> array(N);
    for (int i = 0; i < N; ++i) {
        cin >> array[i];
    }

    // Розподіл на три групи: mod0, mod1, mod2
    auto modComparator = [](int a, int b) {
        if (a % 3 != b % 3) {
            return a % 3 < b % 3; // Спочатку за остачею
        }
        if (a % 3 == 1) {
            return a > b; // Остача 1 — за спаданням
        }
        return a < b; // Інші (остача 0 або 2) — за зростанням
    };

    // Сортуємо масив з урахуванням компаратора
    sort(array.begin(), array.end(), modComparator);

    // Видаляємо дублікати
    array.erase(unique(array.begin(), array.end()), array.end());

    // Вивід результату
    cout << array.size() << "\n";
    for (int num : array) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}

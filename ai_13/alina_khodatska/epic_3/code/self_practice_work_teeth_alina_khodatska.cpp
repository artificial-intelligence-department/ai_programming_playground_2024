#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int* a = new int[n];  // Динамічне виділення пам'яті
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_len = 0; // Максимальна довжина підрядка з загостреними зубами

    // Вкладений цикл для перевірки всіх підрядків
    for (int i = 0; i < n; i++) {
        int current_len = 0;
        for (int j = i; j < n; j++) {
            if (a[j] >= k) { // Якщо зуб загострений
                current_len++;
            }
            else {
                break; // Якщо знайдено елемент, який менший за k, припиняємо перевірку цього підрядка
            }
        }
        max_len = max(max_len, current_len); // Оновлюємо максимальну довжину підрядка
    }

    cout << max_len << endl;

    delete[] a;  // Звільняємо пам'ять
    return 0;
}

// приклад для вводу
// 10 5
// 1 2 3 5 6 7 4 8 9 10


// 10 5
// 1 2 3 5 6 7 4 8 9 10

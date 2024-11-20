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
    int current_len = 0; // Поточна довжина підрядка

    for (int i = 0; i < n; i++) {
        if (a[i] >= k) { // Якщо зуб загострений
            current_len++;
        }
        else {
            max_len = max(max_len, current_len); // Оновлюємо максимальну довжину
            current_len = 0; // Скидаємо поточну довжину
        }
    }

    // Оскільки останній підрядок може бути найдовшим, перевіряємо його ще раз
    max_len = max(max_len, current_len);

    cout << max_len << endl;

    delete[] a;  // Не забуваємо звільнити пам'ять

    return 0;
}

// 10 5
// 1 2 3 5 6 7 4 8 9 10

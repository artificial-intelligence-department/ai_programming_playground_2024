#include <iostream>
using namespace std;

int main() {
    int N, M;

    cin >> N;
    int* a = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cin >> M;
    int* b = new int[M];
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }

    // Знаходимо кількість спільних елементів
    int common_elements = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i] == b[j]) {
                common_elements++;
                break; // Переходимо до наступного елемента з a
            }
        }
    }

    // Знаходимо кількість унікальних елементів
    int* union_array = new int[N + M];
    int unique_count = 0;

    // Додаємо елементи з a
    for (int i = 0; i < N; i++) {
        bool is_unique = true;
        for (int j = 0; j < unique_count; j++) {
            if (union_array[j] == a[i]) {
                is_unique = false;
                break;
            }
        }
        if (is_unique) {
            union_array[unique_count++] = a[i];
        }
    }

    // Додаємо елементи з b
    for (int i = 0; i < M; i++) {
        bool is_unique = true;
        for (int j = 0; j < unique_count; j++) {
            if (union_array[j] == b[i]) {
                is_unique = false;
                break;
            }
        }
        if (is_unique) {
            union_array[unique_count++] = b[i];
        }
    }

    // Вивід результатів
    cout << common_elements << endl;
    cout << unique_count << endl;

    // Звільнення пам'яті
    delete[] a;
    delete[] b;
    delete[] union_array;

    return 0;
}


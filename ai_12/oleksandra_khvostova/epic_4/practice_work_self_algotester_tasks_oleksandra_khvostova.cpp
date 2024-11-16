#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N;
    int* a = new int[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    cin >> M;
    int* b = new int[M];
    for (int i = 0; i < M; ++i) {
        cin >> b[i];
    }

    // Знаходження елементів, які наявні в обох масивах
    int count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (a[i] == b[j]) {
                ++count;
                break;
            }
        }
    }

    // Створюємо об'єднання двох масивів з унікальними елементами
    int* union_array = new int[N + M];
    int union_size = 0;

    // Додаємо всі елементи з першого масиву
    for (int i = 0; i < N; ++i) {
        union_array[union_size++] = a[i];
    }

    // Додаємо тільки ті елементи з другого масиву, яких ще немає в об'єднаному масиві
    for (int i = 0; i < M; ++i) {
        bool found = false;
        for (int j = 0; j < N; ++j) {
            if (b[i] == a[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            union_array[union_size++] = b[i];
        }
    }

    cout << count << endl;
    cout << union_size << endl;

    delete[] a;
    delete[] b;
    delete[] union_array;

    return 0;
}
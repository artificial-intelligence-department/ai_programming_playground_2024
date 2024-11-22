#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int* r = new int[N];
    for (int i = 0; i < N; ++i) {
        cin >> r[i];
    }

    int a, b, c;
    cin >> a >> b >> c;

    int* filtered = new int[N];
    int new_size = 0;

    for (int i = 0; i < N; ++i) {
        if (r[i] != a && r[i] != b && r[i] != c) {
            filtered[new_size++] = r[i];
        }
    }

    // Масив для сум сусідніх елементів
    if (new_size > 1) {
        int* sums = new int[new_size - 1];
        for (int i = 0; i < new_size - 1; ++i) {
            sums[i] = filtered[i] + filtered[i + 1];
        }

        cout << (new_size - 1) << endl;
        for (int i = 0; i < new_size - 1; ++i) {
            cout << sums[i] << " ";
        }
        cout << endl;

        delete[] sums;  // Звільняємо пам'ять для масиву сум
    } else {
        // Якщо не вистачає елементів для створення пар
        cout << 0 << endl;
    }

    // Звільнення пам'яті
    delete[] r;
    delete[] filtered;

    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;  // Розмір масиву
    vector<int> arr(N + 1);  // Масив (індексуємо з 1 для зручності)
    
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    int left = 1;       // Початкова позиція лівого дрона
    int right = N;      // Початкова позиція правого дрона

    // Симуляція польоту дронів
    while (true) {
        // Перевірка перед польотом
        if (left == right) {
            cout << left << " " << right << endl;
            cout << "Collision" << endl;
            return 0;
        }
        if (left + 1 == right) {
            cout << left << " " << right << endl;
            cout << "Stopped" << endl;
            return 0;
        }

        // Оновлення позицій
        left += arr[left];
        right -= arr[right];

        // Перевірка після польоту
        if (left > right) {
            cout << left << " " << right << endl;
            cout << "Miss" << endl;
            return 0;
        }
    }

    return 0;
}




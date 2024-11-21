#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> r(N);
    for (int i = 0; i < N; ++i) {
        cin >> r[i];
    }

    // Якщо лише 2 елементи або менше, немає сенсу викидати щось
    if (N <= 2) {
        cout << 0 << endl;
        return 0;
    }

    int minFatigue = INT_MAX; // Максимально можливе значення для пошуку мінімуму

    for (int i = 0; i < N; ++i) {
        vector<int> temp = r;
        temp.erase(temp.begin() + i); // Викидаємо один елемент

        int maxElement = *max_element(temp.begin(), temp.end()); // Максимальний елемент після видалення
        int minElement = *min_element(temp.begin(), temp.end()); // Мінімальний елемент після видалення

        int fatigue = maxElement - minElement; // Втома для поточного варіанту
        minFatigue = min(minFatigue, fatigue); // Оновлюємо мінімальну втому
    }

    cout << minFatigue << endl;

    return 0;
}

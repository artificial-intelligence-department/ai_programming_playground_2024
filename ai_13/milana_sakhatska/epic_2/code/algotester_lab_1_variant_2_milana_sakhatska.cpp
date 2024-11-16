#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int>& legs, vector<int>& cuts) {
    int n = legs.size();

    // Перевірка чи відпилювання можливе без помилок
    for (int i = 0; i < n; ++i) {
        if (cuts[i] > legs[i]) {
            cout << "ERROR" << endl;
            return false;
        }
    }

    // Відпилюємо ніжки
    for (int i = 0; i < n; ++i) {
        legs[i] -= cuts[i];
    }

    // Перевіряємо чи стіл не перевернеться
    int hmax = *max_element(legs.begin(), legs.end());
    int hmin = *min_element(legs.begin(), legs.end());

    if (hmax >= 2 * hmin) {
        cout << "NO" << endl;
        return false;
    }

    cout << "YES" << endl;
    return true;
}

int main() {
    vector<int> legs(4), cuts(4);

    cout << "Enter the lengths of the 4 legs:" << endl;
    for (int i = 0; i < 4; ++i) {
        cin >> legs[i];
    }

    cout << "Enter the lengths to cut from each leg:" << endl;
    for (int i = 0; i < 4; ++i) {
        cin >> cuts[i];
    }

    check(legs, cuts);

    return 0;
}

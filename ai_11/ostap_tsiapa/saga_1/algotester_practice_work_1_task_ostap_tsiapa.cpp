#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Зчитування кількості пачок печива
    int n;
    cin >> n;

    // Зчитування кількості штук печива в кожній пачці
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Обчислення максимальної кількості печива, яку Марічка може з'їсти
    long long maxCookies = 0;
    for (int i = 0; i < n; ++i) {
        maxCookies += a[i] - 1; // Марічка може з'їсти все, крім 1 штуки в пачці
    }

    // Вивід результату
    cout << maxCookies << endl;

    return 0;
}

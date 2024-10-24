#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> lis(n, 1); // Вектор для зберігання довжини LIS, ініціалізований одиницями

    // Динамічне програмування для обчислення LIS
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i] > a[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    // Знайти максимальне значення в векторі lis
    int max_lis = *max_element(lis.begin(), lis.end());

    cout << max_lis << endl;
    return 0;
}

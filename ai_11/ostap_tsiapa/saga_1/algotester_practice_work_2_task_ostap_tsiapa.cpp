#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    
    // Зчитуємо бажані кількості для кожної страви
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    // Функція для знаходження медіани
    auto get_median = [](vector<int>& v) {
        sort(v.begin(), v.end());
        return v[v.size() / 2];
    };

    // Знаходимо медіани для кожної страви
    int A = get_median(a);
    int B = get_median(b);
    int C = get_median(c);

    // Обчислюємо сумарний ступінь недовіри
    long long total_distrust = 0;
    for (int i = 0; i < n; ++i) {
        total_distrust += abs(A - a[i]) + abs(B - b[i]) + abs(C - c[i]);
    }

    cout << total_distrust << endl;
    
    return 0;
}

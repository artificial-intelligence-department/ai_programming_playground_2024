#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> r(N);
    for (int i = 0; i < N; ++i) {
        cin >> r[i];
    }
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> filtered;
    for (int x : r) {
        if (x != a && x != b && x != c) {
            filtered.push_back(x);
        }
    }

    if (filtered.size() < 2) {
        cout << 0 << endl;
        return 0;
    }

    // Створення масиву сум сусідніх елементів
    vector<int> sums;
    for (size_t i = 0; i < filtered.size() - 1; ++i) {
        sums.push_back(filtered[i] + filtered[i + 1]);
    }

    // Виведення результатів
    cout << sums.size() << endl;
    for (int sum : sums) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}

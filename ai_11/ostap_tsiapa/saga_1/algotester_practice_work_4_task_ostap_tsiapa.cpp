#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int max_length = 0; // Максимальна довжина серії загострених зубів
    int current_length = 0; // Поточна довжина серії

    for (int i = 0; i < n; ++i) {
        if (a[i] >= k) {
            current_length++; // Продовжуємо серію
            max_length = max(max_length, current_length);
        } else {
            current_length = 0; // Серія переривається
        }
    }

    cout << max_length << endl;
    return 0;
}

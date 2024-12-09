#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> companies(n);
    for (int i = 0; i < n; i++) {
        int length;
        cin >> length;
        companies[i] = {length, i + 1}; // {довжина офісу, номер компанії}
    }

    // Сортуємо компанії за довжиною офісу
    sort(companies.begin(), companies.end());

    // Виводимо порядок компаній
    for (int i = 0; i < n; i++) {
        cout << companies[i].second << " ";
    }

    return 0;
}

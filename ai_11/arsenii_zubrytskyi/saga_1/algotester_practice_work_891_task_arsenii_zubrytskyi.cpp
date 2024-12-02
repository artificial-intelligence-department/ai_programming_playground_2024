#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> zenik_candies(n);
    vector<int> marichka_candies(m);

    for (int i = 0; i < n; i++) {
        cin >> zenik_candies[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> marichka_candies[i];
    }

    int min_zenik = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (zenik_candies[i] < min_zenik) {
            min_zenik = zenik_candies[i];
        }
    }

    int min_marichka = INT_MAX;
    for (int i = 0; i < m; i++) {
        if (marichka_candies[i] < min_marichka) {
            min_marichka = marichka_candies[i];
        }
    }

    cout << min_zenik + min_marichka << endl;

    return 0;
}

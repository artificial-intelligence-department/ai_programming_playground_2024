#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main() {
    uint64_t a;
    int N;
    cin >> a >> N;

    vector<pair<int, int>> spells(N);
    for (int i = 0; i < N; ++i) {
        cin >> spells[i].first >> spells[i].second;
    }

    for (const auto& spell : spells) {
        int R = spell.first;
        int C = spell.second;
        --R; --C;

        for (int col = 0; col < 8; ++col) {
            a ^= (1ULL << (R * 8 + col));
        }

        for (int row = 0; row < 8; ++row) {
            a ^= (1ULL << (row * 8 + C));
        }

        a ^= (1ULL << (R * 8 + C));
    }

    cout << a << endl;
    return 0;
}

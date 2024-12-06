#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main() {
    uint64_t a;
    int N;

    cin >> a;
    cin >> N;

    vector<pair<int, int> > spells(N);

    for (int i = 0; i < N; ++i) {
        cin >> spells[i].first >> spells[i].second;
    }

    uint64_t board = a;

    for (int i = 0; i < N; ++i) {
        int row = spells[i].first - 1;
        int col = spells[i].second - 1;

        uint64_t rowMask = (uint64_t)0xFF << (row * 8);

        board ^= rowMask;

        uint64_t colMask = 0;
        for (int i = 0; i < 8; ++i) {
            colMask |= ((uint64_t)1 << (col + i * 8));
        }

        board ^= colMask;

        board ^= ((uint64_t)1 << (row * 8 + col));
    }

    cout << board << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

uint64_t toggle(uint64_t board, int row, int col) {
    for (int c = 0; c < 8; ++c) {
        board ^= (1ULL << (row * 8 + c));
    }
    for (int r = 0; r < 8; ++r) {
        board ^= (1ULL << (r * 8 + col));
    }
    board ^= (1ULL << (row * 8 + col));
    return board;
}

int main() {
    uint64_t a;
    cin >> a;

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int Ri, Ci;
        cin >> Ri >> Ci;
        --Ri;
        --Ci;
        a = toggle(a, Ri, Ci);
    }

    cout << a << endl;
    return 0;
}

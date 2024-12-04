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
        int Ri, Ci;
        cin >> Ri >> Ci;
        spells[i] = {Ri - 1, Ci - 1};
    }

    for (const auto& spell : spells) {
        int row = spell.first;
        int col = spell.second;


        for (int j = 0; j < 8; ++j) {
            a ^= (1ULL << (row * 8 + j));
        }


        for (int i = 0; i < 8; ++i) {
            if (i != row) {
                a ^= (1ULL << (i * 8 + col));
            }
        }
    }

    cout << a << endl;

    return 0;
}

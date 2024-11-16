#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;


void toggle(uint64_t &board, int row, int col) {
    int position = row * 8 + col; 
    board ^= (1ULL << position);  
}

int main() {
    uint64_t board; 
    int N;        

    cin >> board;
    cin >> N;

    vector<pair<int, int>> spells(N);
    for (int i = 0; i < N; ++i) {
        cin >> spells[i].first >> spells[i].second;
        spells[i].first--;  
        spells[i].second--;
    }


    for (const auto &spell : spells) {
        int row = spell.first;
        int col = spell.second;

        for (int c = 0; c < 8; ++c) {
            toggle(board, row, c);
        }


        for (int r = 0; r < 8; ++r) {
            if (r != row) { 
                toggle(board, r, col);
            }
        }
    }


    cout << board << endl;

    return 0;
}

#include <iostream>
#include <cstdint>

using namespace std;

void toggleRow(uint64_t &board, int row) {
    for (int col = 0; col < 8; col++) {
        board ^= (1LL << (row * 8 + col));
    }
}

void toggleCol(uint64_t &board, int col) {
    for (int row = 0; row < 8; row++) {
        board ^= (1LL << (row * 8 + col));
    }
}

int main() {
    uint64_t board;
    int n;
    
    cin >> board >> n;
    
    for (int i = 0; i < n; i++) {
        int row, col;
        cin >> row >> col;
        
        row--;
        col--;
        
        toggleRow(board, row);
        
        toggleCol(board, col);
        
        board ^= (1LL << (row * 8 + col));
    }
    
    cout << board << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

void toggleRow(uint64_t &board, int row) {
    for (int col = 0; col < 8; col++) {
        board ^= (1ULL << (row * 8 + col));
    }
}

void toggleColumn(uint64_t &board, int col) {
    for (int row = 0; row < 8; row++) {
        board ^= (1ULL << (row * 8 + col));
    }
}

int main() {
    uint64_t board;
    int n;
    
    cin >> board >> n;
    
    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        
        r--;
        c--;
        
        toggleRow(board, r);
        
        toggleColumn(board, c);
        
        board ^= (1ULL << (r * 8 + c));
    }
    
    cout << board << endl;

    return 0;
}
#include <iostream>

using namespace std;

void chosen_row(unsigned long long &board, int row) {
    for (int col = 0; col < 8; col++) {
        board ^= (1ULL  << (row * 8 + col));
    }
}

void chosen_column(unsigned  long long &board, int col) {
    for (int row = 0; row < 8; row++) {
        board ^= (1ULL << (row * 8 + col));
    }
}

int main() {
 unsigned long long board;
    int n;
    
    cin >> board >> n;
    
    for (int i = 0; i < n; i++) {
        int R, C;
        cin >> R >> C;
        
        R--;
        C--;
        
        chosen_row(board, R);
        chosen_column(board, C);
        board ^= (1ULL <<  (R * 8 + C));
    }
    
    cout << board << endl;

    return 0;
}
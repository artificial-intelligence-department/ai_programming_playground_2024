#include <iostream>
#include <cstdint> // Для uint64_t
using namespace std;

int main() {
    
    uint64_t board; 
    int n;          
    cin >> board >> n;

    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        r--; 
        c--;
        for (int col = 0; col < 8; col++) {
            board ^= (1ULL << (r * 8 + col));
        }
        for (int row = 0; row < 8; row++) {
            board ^= (1ULL << (row * 8 + c));
        }
        board ^= (1ULL << (r * 8 + c));
    }
    cout << board << endl;
    return 0;
}
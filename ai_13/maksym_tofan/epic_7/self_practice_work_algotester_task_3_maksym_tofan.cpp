#include <iostream>
using namespace std;

int main() {
    unsigned long long a;  
    int N;                 
    cin >> a >> N;

    
    unsigned long long row_mask, col_mask;

    
    for (int i = 0; i < N; ++i) {
        int Ri, Ci;
        cin >> Ri >> Ci;

        
        row_mask = 0;
        for (int j = 0; j < 8; ++j) {
            row_mask |= (1ULL << (8 * (Ri - 1) + j)); 
        }

        
        col_mask = 0;
        for (int j = 0; j < 8; ++j) {
            col_mask |= (1ULL << (8 * j + (Ci - 1))); 
        }

      
        a ^= (row_mask | col_mask); 
    }

   
    cout << a << endl;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    unsigned long long a;
    int N;
    cin >> a;
    cin >> N;
    if (N < 0 || N > 1000) {
        return 0;
    }

    for (int i = 0; i < N; ++i) {
        int Ri, Ci;
        cin >> Ri >> Ci;
        if (Ri < 1 || Ri > 8 || Ci < 1 || Ci > 8) {
            return 0;
        }

        unsigned long long row_mask = 0xFFULL << (8 * (Ri - 1));
        unsigned long long col_mask = 0;
        for (int j = 0; j < 8; ++j) {
            col_mask |= (1ULL << ((Ci - 1) + j * 8));
        }

        a ^= (row_mask | col_mask);
    }

    cout << a << endl;
    return 0;
}

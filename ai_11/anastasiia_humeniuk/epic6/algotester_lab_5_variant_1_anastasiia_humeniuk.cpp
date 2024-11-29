#include <iostream>

using namespace std;

int main() {
    unsigned long long a;
    int N;
    cin >> a >> N;

    for (int i = 0; i < N; i++) {
        int R, C;
        cin >> R >> C;

        R -= 1;
        C -= 1;

        for (int col = 0; col < 8; col++) {
            a ^= (1ULL << (R * 8 + col));
        }

        for (int row = 0; row < 8; row++) {
            a ^= (1ULL << (row * 8 + C));
        }

        a ^= (1ULL << (R * 8 + C));
    }

    cout << a << endl;

    return 0;
}

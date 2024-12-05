//лаб-1-1

#include <iostream>
using namespace std;

int main() {
    long long H, M;
    cin >> H >> M;
    bool win = true;
    
    for (int i = 0; i < 3; i++) {
        long long h, m;
        cin >> h >> m;
        
        if (h > 0 && m > 0) {
            win = false;
        }
        
        H -= h;
        M -= m;
    }

    if (win && H > 0 && M > 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

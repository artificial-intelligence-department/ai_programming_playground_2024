#include <iostream>
using namespace std;

int main() {
    long long L, R;
    cin >> L >> R;
    long long start = (L % 9 == 0) ? L : L + (9 - L % 9);
    if(start > R) cout << 0;
    else cout << (R - start) / 9 + 1;
    return 0;
}

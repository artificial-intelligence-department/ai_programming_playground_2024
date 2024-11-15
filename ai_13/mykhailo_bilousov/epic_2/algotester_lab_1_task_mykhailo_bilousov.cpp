#include <iostream>
using namespace std;

int main() {
    long long h, m, prev_h, prev_m, input_h, input_m;
    bool loss = false;
    cin >> h >> m;
    for(int i = 0; i < 3; i++) {
        cin >> input_h >> input_m;
        prev_h = h;
        prev_m = m;
        h -= input_h;
        m -= input_m;
        if((prev_h > h && prev_m > m)) {
            loss = true;
        }
    }
    cout << ((h > 0 && m > 0 && !loss) ? "YES" : "NO") << endl;
}
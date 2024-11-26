#include <iostream>
using namespace std;

int main() {
    long long h, p, r, s;
    cin >> h >> p >> r >> s;
    if( h < 0 || p < 0 || r < 0 || s < 0 || h > 1e9 || p > 1e9 || r > 1e9 || s > 1e9) return 1;
    long long hp = 0, hr = 0, hs = 0, pr = 0, ps = 0, rs = 0;
    
    hp = (h > p) ? p : h;
    h -= hp;
    p -= hp;
    
    hr = (h > r) ? r : h;
    h -= hr;
    r -= hr;
    
    hs = (h > s) ? s : h;
    h -= hs;
    s -= hs;
    
    pr = (p > r) ? r : p;
    p -= pr;
    r -= pr;

    ps = (p > s) ? s : p;
    p -= ps;
    s -= ps;

    rs = (r > s) ? s : r;
    r -= rs;
    s -= rs;
    
    cout << hp << " " << hr << " " << hs << " " << pr << " " << ps << " " << rs << endl;
    
    return 0;
}

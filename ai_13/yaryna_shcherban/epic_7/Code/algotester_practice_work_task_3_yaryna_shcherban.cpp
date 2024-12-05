#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int x, y;
    cin >> s >> x >> y;

    int up = 0, right = 0;
    for (char c : s) {
        if (c == 'U') {
            up++;
        } else if (c == 'R') {
            right++;
        }
    }

    if (up >= y && right >= x) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

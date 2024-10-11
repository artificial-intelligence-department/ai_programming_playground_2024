#include <iostream>

using namespace std;

int main() {
    long long minn = 1e13, maxx = 0;
    bool error_check = false;
    long long h[4], d[4];

    for (int i = 0; i < 4; i++) {
        cin >> h[i];
        minn = min(minn, h[i]);
        maxx = max(maxx, h[i]);
    }

    for (int i = 0; i < 4; i++) {
        cin >> d[i];
        if (h[i] < d[i]) {
            error_check = true;
        }
    }

    if (error_check) {
        cout << "ERROR" << endl;
        return 0;
    }

    for (int i = 0; i < 4; i++) {
            h[i] -= d[i];
            minn = min(minn, h[i]);

        maxx = 0;
        for (int i = 0; i< 4; i++) {
            maxx = max(maxx, h[i]);
        }

        if (minn * 2 <= maxx) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}
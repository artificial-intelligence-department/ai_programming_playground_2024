#include <iostream>
#include <string>
using namespace std;

int main() {
    string t, s;
    cin >> t >> s;

    int len_t = t.size();
    int len_s = s.size();

    for (int i = 0; i <= len_t - len_s; i++) {
        bool can_place = true;

        for (int j = 0; j < len_s; j++) {
            if (t[i + j] != '?' && t[i + j] != s[j]) {
                can_place = false;
                break;
            }
        }

        if (can_place) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}

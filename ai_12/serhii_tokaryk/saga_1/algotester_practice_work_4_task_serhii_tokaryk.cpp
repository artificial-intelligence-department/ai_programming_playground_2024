#include <iostream>
#include <string>

using namespace std;

int main() {
    string t, s;
    cin >> t >> s;

    int len_t = t.length();
    int len_s = s.length();
    
    if (len_s > len_t) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i <= len_t - len_s; ++i) {
        bool can_match = true;
        
        for (int j = 0; j < len_s; ++j) {
            if (t[i + j] != '?' && t[i + j] != s[j]) {
                can_match = false;
                break;
            }
        }

        if (can_match) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
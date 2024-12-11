#include <iostream>
#include <string>
using namespace std;

int main() {
    string t, s;
    cin >> t >> s;

    int t_len = t.length();
    int s_len = s.length();

    // Перебираємо всі можливі позиції початку рядка s у t
    for (int i = 0; i <= t_len - s_len; ++i) {
        bool canReplace = true;

        // Перевіряємо, чи можна вставити s у t, замінюючи `?`
        for (int j = 0; j < s_len; ++j) {
            if (t[i + j] != '?' && t[i + j] != s[j]) {
                canReplace = false;
                break;
            }
        }
        
        if (canReplace) {
            cout << "YES" << endl;
            return 0;
        }
    }

    // Якщо жодна позиція не підходить, виводимо NO
    cout << "NO" << endl;
    return 0;
}


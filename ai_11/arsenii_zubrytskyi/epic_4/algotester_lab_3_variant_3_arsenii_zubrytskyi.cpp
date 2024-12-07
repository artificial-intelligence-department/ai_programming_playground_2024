#include <iostream>
#include <string>
using namespace std;

string compressString(const string& s) {
    string compressed = "";
    int count = 1;

    for (size_t i = 1; i <= s.length(); i++) {
        // Якщо поточний символ відрізняється від попереднього або ми на останньому символі
        if (i == s.length() || s[i] != s[i - 1]) {
            compressed += s[i - 1]; // Додаємо символ
            if (count > 1) {       // Додаємо кількість, якщо більше 1
                compressed += to_string(count);
            }
            count = 1;            
        } else {
            count++;              
        }
    }

    return compressed;
}

int main() {
    string s;
    cin >> s;

    string compressed = compressString(s);

    cout << compressed << endl;

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

string compressString(const string& s) {
    string compressed = "";
    int count = 1; // Лічильник повторень символів
    
    for (int i = 1; i <= s.length(); ++i) {
        // Перевірка, чи поточний символ такий самий, як попередній
        if (i < s.length() && s[i] == s[i - 1]) {
            count++;
        } else {
            // Додаємо символ і кількість повторень (якщо більше 1)
            compressed += s[i - 1];
            if (count > 1) {
                compressed += to_string(count);
            }
            count = 1; // Скидаємо лічильник
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

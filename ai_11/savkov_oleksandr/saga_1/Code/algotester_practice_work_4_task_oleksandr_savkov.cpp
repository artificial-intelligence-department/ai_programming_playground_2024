#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    string compressed = "";
    int count = 1;

    for (int i = 1; i <= s.size(); i++) {
        if (i < s.size() && s[i] == s[i - 1]) {
            count++;
        } else {
            compressed += s[i - 1];
            if (count > 1) {
                compressed += to_string(count);
            }
            count = 1;
        }
    }

    cout << compressed << endl;
    return 0;
}

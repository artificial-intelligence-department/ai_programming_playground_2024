#include <iostream>
#include <string>

using namespace std;

string compressString(const string& s) {
    string compressed;
    int count = 1;

    for (size_t i = 1; i <= s.size(); i++) {
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

    return compressed;
}

int main() {
    string s;
    cin >> s;
    cout << compressString(s) << endl;
    return 0;
}

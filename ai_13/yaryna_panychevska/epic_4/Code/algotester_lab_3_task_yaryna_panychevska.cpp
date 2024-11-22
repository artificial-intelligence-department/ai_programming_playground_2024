#include <iostream>
#include <string>

using namespace std;

string compressString(const string& s) {
    string compressed = "";
    int count = 1;

    for (size_t i = 0; i < s.length(); ++i) {
        if (i + 1 < s.length() && s[i] == s[i + 1]) {
            count++;
        }
        else {
            compressed += s[i];
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

    string result = compressString(s);
    cout << " " << result << endl;

    return 0;
}

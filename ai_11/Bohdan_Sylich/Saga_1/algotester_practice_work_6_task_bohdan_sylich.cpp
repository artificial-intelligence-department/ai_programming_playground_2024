#include <iostream>
#include <string>
using namespace std;

string encodeRLE(const string& s) {
    string encoded = "";
    int count = 1;

    for (size_t i = 1; i <= s.length(); ++i) {
        if (i < s.length() && s[i] == s[i - 1]) {
            ++count;
        } else {
            encoded += to_string(count) + s[i - 1];
            count = 1;
        }
    }

    return encoded;
}

int main() {
    string s;
    cin >> s;
    cout << encodeRLE(s) << endl;
    return 0;
}

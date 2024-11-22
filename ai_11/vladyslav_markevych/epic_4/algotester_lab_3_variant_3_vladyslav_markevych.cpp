#include <iostream>
#include <string>
using namespace std;

string compressString(const string& s) {
    string compressed;
    int n = s.length();

    for (int i = 0; i < n; ) {
        char currentChar = s[i];
        int count = 0;

        while (i < n && s[i] == currentChar) {
            count++;
            i++;
        }

        compressed += currentChar;
        if (count > 1) {
            compressed += to_string(count);
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
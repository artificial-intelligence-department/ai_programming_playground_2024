#include <iostream>
#include <string>

using namespace std;

string obroblString(const string& s) {
    string obrob;
    int count = 1;

    for (size_t i = 1; i <= s.length(); ++i) {
        if (i < s.length() && s[i] == s[i - 1]) {
            count++;
        } else {
            obrob += s[i - 1];
            if (count > 1) {
                obrob += to_string(count);
            }
            count = 1;
        }
    }
    return obrob;
}

int main() {
    string S;
    cin >> S;
    cout << obroblString(S) << endl;
    return 0;
}
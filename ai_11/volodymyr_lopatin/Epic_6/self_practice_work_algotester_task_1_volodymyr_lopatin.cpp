#include <iostream>
#include <deque>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string s;
    cin >> s;

    if (s.length() < 1 || s.length() > 100000) {
        return 0;
    }

    for (char c : s) {
        if (!isupper(c)) {
            return 0;
        }
    }

    deque<string> result;

    int n = s.size();
    int count = 1;

    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            ++count;
        } else {
            result.push_back(to_string(count) + s[i - 1]);
            count = 1;
        }
    }
    result.push_back(to_string(count) + s[n - 1]);

    for (const auto& segment : result) {
        cout << segment;
    }

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    string result = "";
    int n = s.size();

    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i + 1 < n && s[i] == s[i + 1]) {
            count++;
            i++;
        }
        result += s[i];
        if (count > 1) {
            result += to_string(count);
        }
    }
    cout << result << endl;
    return 0;
}
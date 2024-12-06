#include <iostream>
#include <string>

using namespace std;

bool help_or_no(int k, const string& s) {
    string target = "TOILET";
    int count = 0;
    size_t pos = 0;

    while ((pos = s.find(target, pos)) != string::npos) {
        count++;
        pos += target.length();
        if (count >= k) {
            return true;
        }
    }

    return false;
}

int main() {
    int k;
    string s;
    cin >> k;
    cin.ignore();
    getline(cin, s);

    if (help_or_no(k, s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}


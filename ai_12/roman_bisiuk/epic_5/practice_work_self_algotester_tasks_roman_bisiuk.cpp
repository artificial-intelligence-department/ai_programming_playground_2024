#include <iostream>
#include <string>

using namespace std;

int main() {
    int k;
    string s;

    cin >> k;
    cin >> s;

    string target = "TOILET";
    int count = 0;

    size_t pos = 0;
    while ((pos = s.find(target, pos)) != string::npos) {
        count++;
        pos += target.size();
    }

    if (count >= k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

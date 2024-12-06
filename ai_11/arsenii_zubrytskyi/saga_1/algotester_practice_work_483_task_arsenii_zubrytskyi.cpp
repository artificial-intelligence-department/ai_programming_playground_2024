#include <iostream>
#include <string>

using namespace std;

string canReachTarget(const string& s, int x, int y) {
    int count_R = 0, count_U = 0;

    for (char command : s) {
        if (command == 'R') {
            count_R++;
        } else if (command == 'U') {
            count_U++;
        }
    }

    if (count_R >= x && count_U >= y) {
        return "YES";
    }
    return "NO";
}

int main() {
    string s;
    int x, y;

    cin >> s;
    cin >> x >> y;

    cout << canReachTarget(s, x, y) << endl;

    return 0;
}

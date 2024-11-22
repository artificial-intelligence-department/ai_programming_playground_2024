#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int signal = 15;

    for (char c : s) {
        if (c == 'k') {
            signal = max(signal - 1, 0);
        }
        else if (c == 'p') {
            signal = (signal > 0) ? 15 : 0;
        }
        else if (c == 'z') {
            signal = (signal > 0) ? 0 : 15;
        }
    }

    cout << signal << endl;

    return 0;
}

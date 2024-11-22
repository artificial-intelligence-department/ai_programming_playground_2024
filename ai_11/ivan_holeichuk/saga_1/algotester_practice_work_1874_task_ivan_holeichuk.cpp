#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    string x;
    cin >> n >> x;

    unordered_set<string> pinPairs;

    for (int i = 0; i + n <= x.size(); i++) {
        string pin1 = x.substr(i, n);
        for (int j = i + n; j + n <= x.size(); j++) {
            string pin2 = x.substr(j, n);
            if (pin1 != pin2) {
                pinPairs.insert(min(pin1, pin2) + max(pin1, pin2));
            }
        }
    }

    cout << pinPairs.size() << endl;

    return 0;
}

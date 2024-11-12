#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;

    int count = 0;
    for (char c : input) {
        if (c == '4' || c == '7') count += 1;
    }

    cout << count;

    return 0;
}
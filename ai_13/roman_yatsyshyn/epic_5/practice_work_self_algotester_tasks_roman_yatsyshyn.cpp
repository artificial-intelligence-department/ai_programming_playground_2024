#include <iostream>
#include <string>

using namespace std;

int main() {

    string x;
    cin >> x;

    int count = 0;

    for (char digit : x) {
        if (digit == '4' || digit == '7') {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
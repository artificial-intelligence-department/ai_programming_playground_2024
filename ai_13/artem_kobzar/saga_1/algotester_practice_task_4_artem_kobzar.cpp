#include <iostream>
#include <string>
using namespace std;

int main() {
    string x;
    cin >> x;
    int lucky_count = 0;
    for (char digit : x) {
        if (digit == '4' || digit == '7') {
            lucky_count++;
        }
    }
    cout << lucky_count << endl;
    return 0;
}

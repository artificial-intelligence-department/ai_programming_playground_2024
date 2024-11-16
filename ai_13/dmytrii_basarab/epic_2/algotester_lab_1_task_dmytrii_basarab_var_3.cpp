#include <iostream>

using namespace std;

int main() {
    int i;
long long top, now;
cin >> top;

if (top <= 0) {
    cout << "ERROR" <<endl;
    return 0;
}

for(i = 1;i < 5; i++) {
    cin >> now;

    if (now > top) {
        cout << "LOSS" << endl;
        return 0;
    }

    if (now <= 0) {
    cout << "ERROR" <<endl;
    return 0;
    }

    top = now;


}
    cout << "WIN" << endl;
    return 0;
}

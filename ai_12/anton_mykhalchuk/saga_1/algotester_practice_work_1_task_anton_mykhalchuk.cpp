#include <iostream>

using namespace std;

int main() {
    long long n, a, s = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s += a-1;
    }

    cout << s;
}

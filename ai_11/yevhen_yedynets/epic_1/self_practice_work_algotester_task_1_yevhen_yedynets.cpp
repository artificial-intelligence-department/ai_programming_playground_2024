#include <iostream>
using namespace std;

int main() {
    long n, a;
    long long cookies = 0;

    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a > 0)
            cookies += a - 1;
    }

    cout << cookies;
    
    return 0;
}
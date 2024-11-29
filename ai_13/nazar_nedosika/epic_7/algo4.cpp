#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long totalCookies = 0; 
    int cookies;

    for (int i = 0; i < n; ++i) {
        cin >> cookies;
        if (cookies > 0) {
            totalCookies += cookies - 1;
        }
    }
    cout << totalCookies << endl;
    return 0;
}
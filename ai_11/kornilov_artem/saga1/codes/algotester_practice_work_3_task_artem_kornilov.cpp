#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    

    long long* cookies = new long long[n];

    for (int i = 0; i < n; i++) {
        cin >> cookies[i];
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(cookies[i]-1);
    }

    cout << sum << endl;

    delete[] cookies;

    cookies = nullptr;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    long long total_cookies = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_cookies += a[i];
    }

    long long max_cookies = total_cookies - n;

    cout << max_cookies << endl;
    return 0;
}

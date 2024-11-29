#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long max_eaten = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            max_eaten += a[i] - 1;
        }
    }

    cout << max_eaten << endl;

    return 0;
}

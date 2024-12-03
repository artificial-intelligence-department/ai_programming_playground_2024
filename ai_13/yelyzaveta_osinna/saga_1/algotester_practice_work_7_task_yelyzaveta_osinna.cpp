#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long find_median(vector<int>& values) {
    size_t n = values.size();
    sort(values.begin(), values.end());
    if (n % 2 == 0) {
        return (values[n / 2 - 1] + values[n / 2]) / 2;
    } else {
        return values[n / 2];
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    long long A = find_median(a);
    long long B = find_median(b);
    long long C = find_median(c);

    long long total_mistrust = 0;

    for (int i = 0; i < n; ++i) {
        total_mistrust += abs(a[i] - A) + abs(b[i] - B) + abs(c[i] - C);
    }

    cout << total_mistrust << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> s(n), b(k);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }

    sort(s.rbegin(), s.rend());
    sort(b.rbegin(), b.rend());

    long long totalBeauty = 0;
    multiset<int> brushes(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        if (brushes.empty()) {
            break;
        }

        auto it = brushes.end();
        --it;
        int maxBrush = *it;
        totalBeauty += static_cast<long long>(s[i]) * maxBrush;

        brushes.erase(it);
        if (maxBrush > 1) {
            brushes.insert(maxBrush - 1);
        }
    }

    cout << totalBeauty << endl;

    return 0;
}



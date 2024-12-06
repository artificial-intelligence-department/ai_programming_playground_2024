#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_streak = 0, current_streak = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= k) {
            current_streak++;
            max_streak = max(max_streak, current_streak);
        } else {
            current_streak = 0;
        }
    }

    cout << max_streak << endl;
    return 0;
}


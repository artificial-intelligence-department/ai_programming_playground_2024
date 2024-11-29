#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int maxStreak = 0;
    int currentStreak = 0;

    for (int i = 0; i < n; ++i) {
        int sharpness;
        cin >> sharpness;

        if (sharpness >= k) {
            ++currentStreak;
        } else {
            currentStreak = 0;
        }

        maxStreak = max(maxStreak, currentStreak);
    }

    cout << maxStreak << endl;
    return 0;
}

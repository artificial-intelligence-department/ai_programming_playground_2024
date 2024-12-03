#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int k = 0; k < n; ++k) cin >> v[k];

    int score1 = 1;
    int score2 = n;
    int left = 0;
    int right = n - 1;

    while (left != right && left < right && right != left + 1) {
        score1 += v[left];
        left += v[left];
        score2 -= v[right];
        right -= v[right];
    }

    if (left == right)
        cout << score1 << " " << score2 << "\nCollision";
    else if (right == left + 1)
        cout << score1 << " " << score2 << "\nStopped";
    else
        cout << score1 << " " << score2 << "\nMiss";

    return 0;
}

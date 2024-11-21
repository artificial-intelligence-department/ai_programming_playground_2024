#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> r(N);
    for (int i = 0; i < N; ++i) {
        cin >> r[i];
    }

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    sort(r.begin(), r.end());

    int minDifference = r[N - 1] - r[1];
    minDifference = min(minDifference, r[N - 2] - r[0]);

    cout << minDifference << endl;

    return 0;
}

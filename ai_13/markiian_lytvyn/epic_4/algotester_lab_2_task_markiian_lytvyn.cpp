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
    if (N <= 2) {
        cout << 0 << endl;
        return 0;
    }
    sort(r.begin(), r.end());
    int min_fatigue1 = r[N-1] - r[1];
    int min_fatigue2 = r[N-2] - r[0];
    if (min_fatigue1 > min_fatigue2) {
        cout << min_fatigue2 << endl;
    }
    else {
        cout << min_fatigue1 << endl;
    }
    return 0;
}
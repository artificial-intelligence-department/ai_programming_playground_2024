#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimize_fatigue(int N, vector<int>& r) {
    if (N == 1) return 0;
    sort(r.begin(), r.end());
    int fatigue1 = r[N - 1] - r[1];
    int fatigue2 = r[N - 2] - r[0];
    return min(fatigue1, fatigue2);
}

int main() {
    int N;
    cin >> N;
    vector<int> r(N);
    for (int i = 0; i < N; i++) cin >> r[i];
    cout << minimize_fatigue(N, r) << endl;
    return 0;
}

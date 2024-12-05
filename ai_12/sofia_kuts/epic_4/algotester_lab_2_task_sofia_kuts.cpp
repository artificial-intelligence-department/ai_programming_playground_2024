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

    int removeMinFatigue = r[N - 2] - r[0];

    int removeMaxFatigue = r[N - 1] - r[1];

    cout << min(removeMinFatigue, removeMaxFatigue) << endl;

    return 0;
}


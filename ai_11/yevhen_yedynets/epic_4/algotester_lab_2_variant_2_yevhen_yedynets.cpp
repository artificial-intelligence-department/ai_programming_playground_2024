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

    int a, b, c;
    cin >> a >> b >> c;

    r.erase(remove(r.begin(), r.end(), a), r.end());
    r.erase(remove(r.begin(), r.end(), b), r.end());
    r.erase(remove(r.begin(), r.end(), c), r.end());

    int N_new = r.size();

    if (N_new < 2) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> sum_array(N_new - 1);
    for (int i = 0; i < N_new - 1; ++i) {
        sum_array[i] = r[i] + r[i + 1];
    }

    cout << N_new - 1 << endl;
    for (int i = 0; i < N_new - 1; ++i) {
        cout << sum_array[i] << " ";
    }

    return 0;
}
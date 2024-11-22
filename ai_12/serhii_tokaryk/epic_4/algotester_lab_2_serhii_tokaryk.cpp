#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> r(N);
    for (int i = 0; i < N; i++) {
        cin >> r[i];
    }

    int a, b, c;
    cin >> a >> b >> c;

 
    vector<int> filtered;
    for (int i = 0; i < N; i++) {
        if (r[i] != a && r[i] != b && r[i] != c) {
            filtered.push_back(r[i]);
        }
    }

    int M = filtered.size();

   
    if (M < 2) {
        cout << 0 << "\n";
        return 0;
    }

   
    vector<int> sums(M - 1);
    for (int i = 0; i < M - 1; i++) {
        sums[i] = filtered[i] + filtered[i + 1];
    }

    cout << M - 1 << "\n";
    for (int i = 0; i < M - 1; i++) {
        cout << sums[i] << " ";
    }
    cout << endl;

    return 0;
}
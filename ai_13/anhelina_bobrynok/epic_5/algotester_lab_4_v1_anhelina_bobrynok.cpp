#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    set<int> unique_set(a.begin(), a.end());

    vector<int> sorted(unique_set.begin(), unique_set.end());

    cout << sorted.size() << endl;

    rotate(sorted.begin(), sorted.begin() + K % sorted.size(), sorted.end());

    for (int x : sorted) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}



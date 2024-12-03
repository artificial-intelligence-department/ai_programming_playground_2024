#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    auto c = unique(a.begin(), a.end());
    a.erase(c, a.end());
     K %= a.size();
    rotate(a.begin(), a.begin() + K, a.end());
    
    cout << a.size() << endl;
    for (const int& num : a) {
        cout << num << " ";
    }
    return 0;
}

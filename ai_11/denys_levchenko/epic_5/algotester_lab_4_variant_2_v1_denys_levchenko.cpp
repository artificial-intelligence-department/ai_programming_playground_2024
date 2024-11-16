#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    N = a.size();
    cout << N << endl;

    rotate(a.begin(), a.begin() + K % N, a.end());

    for (int num : a) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

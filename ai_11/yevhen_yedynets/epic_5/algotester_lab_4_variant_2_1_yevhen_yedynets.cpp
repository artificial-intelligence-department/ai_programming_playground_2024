#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);

    for (int i = 0; i < N; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    int new_size = a.size();
    rotate(a.begin(), a.begin() + (K % new_size), a.end());

    cout << new_size << "\n";
    for (int x : a)
        cout << x << " ";
        
    return 0;
}

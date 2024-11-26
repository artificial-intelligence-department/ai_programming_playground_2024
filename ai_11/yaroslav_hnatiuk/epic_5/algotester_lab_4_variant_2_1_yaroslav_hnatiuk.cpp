#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> vec(N);
    for (int i = 0; i < N; i++) cin >> vec[i];

    sort(vec.begin(), vec.end());
    auto dub = unique(vec.begin(), vec.end());
    vec.erase(dub, vec.end());

    K %= vec.size();
    rotate(vec.begin(), vec.begin( ) + K, vec.end());

    cout << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";

    return 0;
}


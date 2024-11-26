#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> vec(N);
    for (int i = 0; i < N; ++i) cin >> vec[i]; 
    
    auto p1 = partition(vec.begin(), vec.end(), [](int x) {return x % 3 == 0;});
    auto p2 = partition(p1, vec.end(), [](int x) {return x % 3 == 1;});
    
    sort(vec.begin(), p1);
    sort(p1, p2, greater<int>());
    sort(p2, vec.end());

    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    cout << vec.size() << endl;
    for (int x : vec) cout << x << " ";

    return 0;
}

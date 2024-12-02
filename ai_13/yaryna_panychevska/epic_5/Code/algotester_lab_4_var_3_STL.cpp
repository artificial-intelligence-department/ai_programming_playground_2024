#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Використання STL
int main() {
    int n;
    cin >> n;

    vector <int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    auto predicate0 = [](int i) {return i % 3 == 0; };
    auto predicate1 = [](int i) {return i % 3 == 1; };

    auto vec_0 = partition(vec.begin(), vec.end(), predicate0);
    auto vec_1 = partition(vec_0, vec.end(), predicate1);

    sort(vec.begin(), vec_0);
    sort(vec_0, vec_1, greater<int>());
    sort(vec_1, vec.end());

    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    int new_size = vec.size();

    cout << new_size << endl;
    for (int x : vec) {
        cout << x << " ";
    }
    return 0;
}
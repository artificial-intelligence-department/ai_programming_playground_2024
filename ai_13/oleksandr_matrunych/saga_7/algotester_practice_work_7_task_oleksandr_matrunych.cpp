#include <iostream>
#include <set>

using namespace std;

int main() {
    int N;

    cin >> N;
    int array1[N];
    for (int i = 0; i < N; ++i) {
        cin >> array1[i];
    }
    int M;
    cin >> M;
    int array2[M];
    for (int i = 0; i < M; ++i) {
        cin >> array2[i];
    }

    set<int> set1, set2;

    for (int i = 0; i < N; ++i) {
        set1.insert(array1[i]);
    }
    for (int i = 0; i < M; ++i) {
        set2.insert(array2[i]);
    }

    int common_count = 0;
    for (int x : set1) {
        if (set2.count(x)) {
            ++common_count;
        }
    }

    set<int> union_set = set1;
    union_set.insert(set2.begin(), set2.end());

    cout << common_count << endl;
    cout << union_set.size() << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vector(const vector<int>& v) {
    cout << v.size() << endl;
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];

    // Сортуємо масиви
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // 1. Різниця N-M
    vector<int> diff_nm;
    set_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(diff_nm));
    print_vector(diff_nm);

    // 2. Різниця M-N
    vector<int> diff_mn;
    set_difference(b.begin(), b.end(), a.begin(), a.end(), back_inserter(diff_mn));
    print_vector(diff_mn);

    // 3. Перетин
    vector<int> intersection;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(intersection));
    print_vector(intersection);

    // 4. Об'єднання
    vector<int> union_set;
    set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(union_set));
    print_vector(union_set);

    // 5. Симетрична різниця
    vector<int> sym_diff;
    set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(sym_diff));
    print_vector(sym_diff);

    return 0;
}

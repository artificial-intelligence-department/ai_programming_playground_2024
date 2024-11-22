#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void print_set(const set<int>& s) {
    cout << s.size() << endl;
    for (int x : s) cout << x << " ";
    if (!s.empty()) cout << endl;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    cin >> m;
    vector<int> b(m);
    for (int& x : b) cin >> x;

    set<int> sa(a.begin(), a.end()), sb(b.begin(), b.end()), res;

    set_difference(sa.begin(), sa.end(), sb.begin(), sb.end(), inserter(res, res.begin()));
    print_set(res);
    res.clear();

    set_difference(sb.begin(), sb.end(), sa.begin(), sa.end(), inserter(res, res.begin()));
    print_set(res);
    res.clear();

    set_intersection(sa.begin(), sa.end(), sb.begin(), sb.end(), inserter(res, res.begin()));
    print_set(res);
    res.clear();

    set_union(sa.begin(), sa.end(), sb.begin(), sb.end(), inserter(res, res.begin()));
    print_set(res);
    res.clear();

    set_symmetric_difference(sa.begin(), sa.end(), sb.begin(), sb.end(), inserter(res, res.begin()));
    print_set(res);

    return 0;
}
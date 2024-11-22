#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> custom_difference(const set<int>& a, const set<int>& b) {
    vector<int> result;
    for (int x : a) {
        if (b.find(x) == b.end()) {
            result.push_back(x);
        }
    }
    return result;
}

vector<int> custom_intersection(const set<int>& a, const set<int>& b) {
    vector<int> result;
    for (int x : a) {
        if (b.find(x) != b.end()) {
            result.push_back(x);
        }
    }
    return result;
}

vector<int> custom_union(const set<int>& a, const set<int>& b) {
    vector<int> result(a.begin(), a.end());
    for (int x : b) {
        if (a.find(x) == a.end()) {
            result.push_back(x);
        }
    }
    sort(result.begin(), result.end());
    return result;
}

vector<int> custom_symmetric_difference(const set<int>& a, const set<int>& b) {
    vector<int> result;
    for (int x : a) {
        if (b.find(x) == b.end()) {
            result.push_back(x);
        }
    }
    for (int x : b) {
        if (a.find(x) == a.end()) {
            result.push_back(x);
        }
    }
    sort(result.begin(), result.end());
    return result;
}

void print_result(const vector<int>& v) {
    cout << v.size() << endl;
    for (int x : v) cout << x << " ";
    if (!v.empty()) cout << endl;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    cin >> m;
    vector<int> b(m);
    for (int& x : b) cin >> x;

    set<int> sa(a.begin(), a.end()), sb(b.begin(), b.end());

    vector<int> res = custom_difference(sa, sb);
    print_result(res);

    res = custom_difference(sb, sa);
    print_result(res);

    res = custom_intersection(sa, sb);
    print_result(res);

    res = custom_union(sa, sb);
    print_result(res);

    res = custom_symmetric_difference(sa, sb);
    print_result(res);

    return 0;
}
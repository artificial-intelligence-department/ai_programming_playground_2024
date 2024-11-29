
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<int>& res) {
    cout << res.size() << endl;
    for (int x : res) cout << x << " ";
    cout << endl;
}

vector<int> un(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) res.push_back(a[i++]);
        else if (b[j] < a[i]) res.push_back(b[j++]);
        else {
            res.push_back(a[i]);
            i++; j++;
        }
    }
    while (i < a.size()) res.push_back(a[i++]);
    while (j < b.size()) res.push_back(b[j++]);
    return res;
}

vector<int> inter(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) i++;
        else if (b[j] < a[i]) j++;
        else {
            res.push_back(a[i]);
            i++; j++;
        }
    }
    return res;
}

vector<int> diff(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) res.push_back(a[i++]);
        else if (b[j] < a[i]) j++;
        else {
            i++;
            j++;
        }
    }
    while (i < a.size()) res.push_back(a[i++]);
    return res;
}

vector<int> symDiff(const vector<int>& a, const vector<int>& b) {
    vector<int> res1 = diff(a, b);
    vector<int> res2 = diff(b, a);
    return un(res1, res2);
}

int main() {
    int N, M;
    cin >> N;
    vector<int> n(N);
    for (int i = 0; i < N; i++) {
        cin >> n[i];
    }
    cin >> M;
    vector<int> m(M);
    for (int i = 0; i < M; i++) {
        cin >> m[i];
    }
    sort(n.begin(), n.end());
    sort(m.begin(), m.end());

    vector<int> d1 = diff(n, m);
    vector<int> d2 = diff(m, n);
    vector<int> interRes = inter(n, m);
    vector<int> unRes = un(n, m);
    vector<int> symRes = symDiff(n, m);

    print(d1);
    print(d2);
    print(interRes);
    print(unRes);
    print(symRes);

    return 0;
}
```
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void Print(vector<int> res){
        cout << res.size() << endl;
        for (int x : res) {
            cout << x << " ";
        }
        cout << endl;
}

vector<int> Diff(vector<int> a, vector<int> b){
    vector<int> res;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            res.push_back(a[i++]);
        } else if (b[j] < a[i]) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    
    while (i < a.size()) {
        res.push_back(a[i++]);
    }
    return res;
}

vector<int> Intersect(vector<int> n, vector<int> m) {
    vector<int> res;
    int i = 0, j = 0;
    while (i < n.size() && j < m.size()) {
        if (n[i] < m[j]) {
            i++;
        } else if (m[j] < n[i]) {
            j++;
        } else {
            res.push_back(n[i]);
            i++; 
            j++;
        }
    }
    return res;
}

vector<int> Union(vector<int> n, vector<int> m) {
    vector<int> res;
    int i = 0, j = 0;
    while (i < n.size() && j < m.size()) {
        if (n[i] < m[j]) {
            res.push_back(n[i++]);
        } else if (m[j] < n[i]) {
            res.push_back(m[j++]);
        } else {
            res.push_back(n[i]);
            i++; j++;
        }
    }
    
    while (i < n.size()) {
        res.push_back(n[i++]);
    }
    while (j < m.size()) {
        res.push_back(m[j++]);
    }
    return res;
}

vector<int> SymmDiff(vector<int> n, vector<int> m) {
    vector<int> res1 = Diff(n, m);
    vector<int> res2 = Diff(m, n);
    return Union(res1, res2);
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

    vector<int> diff1 = Diff(n, m);
    Print(diff1);
    vector<int> diff2 = Diff(m, n);
    Print(diff2);
    vector<int> intersection = Intersect(n, m);
    Print(intersection);
    vector<int> union_set = Union(n, m);
    Print(union_set);
    vector<int> sym_diff = SymmDiff(n, m);
    Print(sym_diff);

    return 0;
}
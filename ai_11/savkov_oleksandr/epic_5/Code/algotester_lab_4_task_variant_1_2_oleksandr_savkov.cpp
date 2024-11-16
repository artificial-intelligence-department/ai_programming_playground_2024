#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display(const vector<int>& spys) {
    cout << spys.size() << endl;
    for (auto el : spys) {
        cout << el << " ";
    }
    cout << endl;
}

vector<int> difference(const vector<int>& v1, const vector<int>& v2) {
    vector<int> result;
    for (int x : v1) {
        if (find(v2.begin(), v2.end(), x) == v2.end()) {
            result.push_back(x);
        }
    }
    return result;
}

vector<int> intersection(const vector<int>& v1, const vector<int>& v2) {
    vector<int> result;
    for (int x : v1) {
        if (find(v2.begin(), v2.end(), x) != v2.end()) {
            result.push_back(x);
        }
    }
    return result;
}

vector<int> union_set(const vector<int>& v1, const vector<int>& v2) {
    vector<int> result = v1;
    for (int x : v2) {
        if (find(v1.begin(), v1.end(), x) == v1.end()) {
            result.push_back(x);
        }
    }
    return result;
}

vector<int> symmetric_difference(const vector<int>& v1, const vector<int>& v2) {
    vector<int> result;
    for (int x : v1) {
        if (find(v2.begin(), v2.end(), x) == v2.end()) {
            result.push_back(x);
        }
    }
    for (int x : v2) {
        if (find(v1.begin(), v1.end(), x) == v1.end()) {
            result.push_back(x);
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> nKil(n);
    for (int i = 0; i < n; i++) {
        cin >> nKil[i];
    }

    int m;
    cin >> m;
    vector<int> mKil(m);
    for (int i = 0; i < m; i++) {
        cin >> mKil[i];
    }

    sort(nKil.begin(), nKil.end());
    sort(mKil.begin(), mKil.end());

    vector<int> rizn1 = difference(nKil, mKil);
    vector<int> rizn2 = difference(mKil, nKil);
    vector<int> per = intersection(nKil, mKil);
    vector<int> obje = union_set(nKil, mKil);
    vector<int> symriz = symmetric_difference(nKil, mKil);

    display(rizn1);
    display(rizn2);
    display(per);
    display(obje);
    display(symriz);

    return 0;
}

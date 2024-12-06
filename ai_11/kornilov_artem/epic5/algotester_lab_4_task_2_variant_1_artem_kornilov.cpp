#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(const vector<int>& res) {
    cout << res.size() << endl;
    for (int x : res) cout << x << " ";
    cout << endl;
}

vector<int> vector_union(const vector<int>& a, const vector<int>& b) {
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

vector<int> intersection(const vector<int>& a, const vector<int>& b) {
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

vector<int> difference(const vector<int>& a, const vector<int>& b) {
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

vector<int> symmetric_difference(const vector<int>& a, const vector<int>& b) {
    vector<int> res1 = difference(a, b);
    vector<int> res2 = difference(b, a);
    return vector_union(res1, res2);
}

int main() {
    int sz1, sz2;
    cin >> sz1;
    if (sz1 < 1 || sz1 > 100) {
        return 0;
    }
    vector<int> vec1(sz1);
    for (int i = 0; i < sz1; i++) {
        cin >> vec1[i];
         if (vec1[i] < 1 || vec1[i] > 100) {
            return 0;
        }
    }
    cin >> sz2;
    if (sz2 < 1 || sz2 > 100) {
        return 0;
    }
    vector<int> vec2(sz2);
    for (int i = 0; i < sz2; i++) {
        cin >> vec2[i];
        if (vec2[i] < 1 || vec2[i] > 100) {
            return 0;
        }
    }
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    vector<int> d1 = difference(vec1, vec2);
    vector<int> d2 = difference(vec2, vec1);
    vector<int> interRes = intersection(vec1, vec2);
    vector<int> unRes = vector_union(vec1, vec2);
    vector<int> symRes = symmetric_difference(vec1, vec2);

    print_vector(d1);
    print_vector(d2);
    print_vector(interRes);
    print_vector(unRes);
    print_vector(symRes);

    return 0;
}
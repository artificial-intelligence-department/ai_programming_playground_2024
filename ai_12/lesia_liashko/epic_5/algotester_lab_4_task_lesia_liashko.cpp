#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> difference(const vector<int>& a, const vector<int>& b) {
    unordered_set<int> b_elements(b.begin(), b.end());
    vector<int> result;
    for (int num : a) {
        if (b_elements.find(num) == b_elements.end()) {
            result.push_back(num);
        }
    }
    return result;
}

vector<int> intersection(const vector<int>& a, const vector<int>& b) {
    unordered_set<int> a_elements(a.begin(), a.end());
    vector<int> result;
    for (int num : b) {
        if (a_elements.find(num) != a_elements.end()) {
            result.push_back(num);
        }
    }
    return result;
}

vector<int> unionSets(const vector<int>& a, const vector<int>& b) {
    unordered_set<int> elements(a.begin(), a.end());
    elements.insert(b.begin(), b.end());
    vector<int> result(elements.begin(), elements.end());
    sort(result.begin(), result.end());
    return result;
}

vector<int> symmetricDifference(const vector<int>& a, const vector<int>& b) {
    unordered_set<int> a_elements(a.begin(), a.end());
    unordered_set<int> b_elements(b.begin(), b.end());
    vector<int> result;

    for (int num : a) {
        if (b_elements.find(num) == b_elements.end()) {
            result.push_back(num);
        }
    }

    for (int num : b) {
        if (a_elements.find(num) == a_elements.end()) {
            result.push_back(num);
        }
    }

    sort(result.begin(), result.end());
    return result;
}

int main() {
    int N, M;

    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    cin >> M;
    vector<int> b(M);
    for (int i = 0; i < M; ++i) {
        cin >> b[i];
    }

    vector<int> diff_a_b = difference(a, b);
    vector<int> diff_b_a = difference(b, a);
    vector<int> intersect = intersection(a, b);
    vector<int> union_ab = unionSets(a, b);
    vector<int> sym_diff = symmetricDifference(a, b);

    cout << diff_a_b.size() << endl;
    for (int num : diff_a_b) {
        cout << num << " ";
    }
    cout << endl;

    cout << diff_b_a.size() << endl;
    for (int num : diff_b_a) {
        cout << num << " ";
    }
    cout << endl;

    cout << intersect.size() << endl;
    for (int num : intersect) {
        cout << num << " ";
    }
    cout << endl;

    cout << union_ab.size() << endl;
    for (int num : union_ab) {
        cout << num << " ";
    }
    cout << endl;

    cout << sym_diff.size() << endl;
    for (int num : sym_diff) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

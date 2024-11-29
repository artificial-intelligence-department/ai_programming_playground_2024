#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;

    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cin >> M;
    vector<int> b(M);
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> diff;
    set_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(diff));
    cout << diff.size() << endl;
    for (size_t i = 0; i < diff.size(); i++) {
        if (i > 0) cout << " ";
        cout << diff[i];
    }
    cout << endl;

    vector<int> revDiff;
    set_difference(b.begin(), b.end(), a.begin(), a.end(), back_inserter(revDiff));
    cout << revDiff.size() << endl;
    for (size_t i = 0; i < revDiff.size(); i++) {
        if (i > 0) cout << " ";
        cout << revDiff[i];
    }
    cout << endl;

    vector<int> intersec;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(intersec));
    cout << intersec.size() << endl;
    for (size_t i = 0; i < intersec.size(); i++) {
        if (i > 0) cout << " ";
        cout << intersec[i];
    }
    cout << endl;

    vector<int> unio;
    set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(unio));
    cout << unio.size() << endl;
    for (size_t i = 0; i < unio.size(); i++) {
        if (i > 0) cout << " ";
        cout << unio[i];
    }
    cout << endl;

    vector<int> symDiff;
    set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(symDiff));
    cout << symDiff.size() << endl;
    for (size_t i = 0; i < symDiff.size(); i++) {
        if (i > 0) cout << " ";
        cout << symDiff[i];
    }
    cout << endl;

    return 0;
}

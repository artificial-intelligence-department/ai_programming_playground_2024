#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void PrintResult(const vector<int>& result) {
    cout << result.size() << endl;
    for (int elm : result) {
        cout << elm << " ";
    }
    cout << endl << endl;
}

int main() {
    int sizeN, sizeM;
    cin >> sizeN;
    vector<int> N(sizeN);
    for (int i = 0; i < sizeN; i++) {
        cin >> N[i];
    }

    cin >> sizeM;
    vector<int> M(sizeM);
    for (int i = 0; i < sizeM; i++) {
        cin >> M[i];
    }

    sort(N.begin(), N.end());
    sort(M.begin(), M.end());

    vector<int> result;

    result.resize(N.size());
    auto it = set_difference(N.begin(), N.end(), M.begin(), M.end(), result.begin());
    result.resize(it - result.begin());
    PrintResult(result);

    result.resize(M.size());
    it = set_difference(M.begin(), M.end(), N.begin(), N.end(), result.begin());
    result.resize(it - result.begin());
    PrintResult(result);

    result.resize(min(N.size(), M.size()));
    it = set_intersection(N.begin(), N.end(), M.begin(), M.end(), result.begin());
    result.resize(it - result.begin());
    PrintResult(result);

    result.resize(N.size() + M.size());
    it = set_union(N.begin(), N.end(), M.begin(), M.end(), result.begin());
    result.resize(it - result.begin());
    PrintResult(result);

    result.resize(N.size() + M.size());
    it = set_symmetric_difference(N.begin(), N.end(), M.begin(), M.end(), result.begin());
    result.resize(it - result.begin());
    PrintResult(result);

    return 0;
}

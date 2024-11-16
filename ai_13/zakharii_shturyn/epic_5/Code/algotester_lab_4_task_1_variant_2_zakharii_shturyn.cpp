//дискретка
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void Print(vector<short> res) {
    cout << res.size() << endl;
    for(short elm : res) {
        cout << elm << " ";
    }
    cout << endl << endl;
}

int main() {

    short sizeN, sizeM;
    cin >> sizeN;
    vector<short> N(sizeN);
    for(int i = 0; i < sizeN; i++) {
        cin >> N[i];
    }
    cin >> sizeM;
    vector<short> M(sizeM);
    for(int i = 0; i < sizeM; i++) {
        cin >> M[i];
    }

    sort(N.begin(), N.end());
    sort(M.begin(), M.end());

    vector<short> res;
    set_difference(N.begin(), N.end(), M.begin(), M.end(), back_inserter(res));
    Print(res);
    res.clear();

    set_difference(M.begin(), M.end(), N.begin(), N.end(), back_inserter(res));
    Print(res);
    res.clear();

    set_intersection(N.begin(), N.end(), M.begin(), M.end(), back_inserter(res));
    Print(res);
    res.clear();

    set_union(N.begin(), N.end(), M.begin(), M.end(), back_inserter(res));
    Print(res);
    res.clear();

    set_symmetric_difference(N.begin(), N.end(), M.begin(), M.end(), back_inserter(res));
    Print(res);
    res.clear();

    return 0;
}
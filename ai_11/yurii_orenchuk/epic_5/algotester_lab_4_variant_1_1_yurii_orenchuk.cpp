#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

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

    vector<int> diff_N_M;
    set_difference(n.begin(), n.end(), m.begin(), m.end(), back_inserter(diff_N_M));
    cout << diff_N_M.size() << endl;
    for (size_t i = 0; i < diff_N_M.size(); i++) {
        if (i > 0) cout << " ";
        cout << diff_N_M[i];
    }
    cout << endl;

    vector<int> diff_M_N;
    set_difference(m.begin(), m.end(), n.begin(), n.end(), back_inserter(diff_M_N));
    cout << diff_M_N.size() << endl;
    for (size_t i = 0; i < diff_M_N.size(); i++) {
        if (i > 0) cout << " ";
        cout << diff_M_N[i];
    }
    cout << endl;

    vector<int> intersec;
    set_intersection(n.begin(), n.end(), m.begin(), m.end(), back_inserter(intersec));
    cout << intersec.size() << endl;
    for (size_t i = 0; i < intersec.size(); i++) {
        if (i > 0) cout << " ";
        cout << intersec[i];
    }
    cout << endl;

    vector<int> uni;
    set_union(n.begin(), n.end(), m.begin(), m.end(), back_inserter(uni));
    cout << uni.size() << endl;
    for (size_t i = 0; i < uni.size(); i++) {
        if (i > 0) cout << " ";
        cout << uni[i];
    }
    cout << endl;

    vector<int> diff_simm;
    set_symmetric_difference(n.begin(), n.end(), m.begin(), m.end(), back_inserter(diff_simm));
    cout << diff_simm.size() << endl;
    for (size_t i = 0; i < diff_simm.size(); i++) {
        if (i > 0) cout << " ";
        cout << diff_simm[i];
    }
    cout << endl;

    return 0;
}
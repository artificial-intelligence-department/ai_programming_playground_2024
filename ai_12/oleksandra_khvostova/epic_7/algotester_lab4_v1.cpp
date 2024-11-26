#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

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

    vector<int> intersection, symmetric_difference, difference1, difference2, unite;

    set_intersection(n.begin(), n.end(), m.begin(), m.end(), back_inserter(intersection));
    set_difference(n.begin(), n.end(), m.begin(), m.end(), back_inserter(difference1));
    set_difference(m.begin(), m.end(), n.begin(), n.end(), back_inserter(difference2));
    set_symmetric_difference(n.begin(), n.end(), m.begin(), m.end(), back_inserter(symmetric_difference));
    set_union(n.begin(), n.end(), m.begin(), m.end(), back_inserter(unite));

    cout << difference1.size() << endl;
    for (int i=0; i<difference1.size(); i++) {
        cout << difference1[i] << " ";
    }
    cout << endl<<endl;

    cout << difference2.size() << endl;
    for (int i=0; i<difference2.size(); i++) {
        cout << difference2[i] << " ";
    }
    cout << endl<<endl;

    cout << intersection.size() << endl;
    for (int i=0; i<intersection.size(); i++) {
        cout << intersection[i] << " ";
    }
    cout << endl<<endl;

    cout << unite.size() << endl;
    for (int i=0; i<unite.size(); i++) {
        cout << unite[i] << " ";
    }
    cout << endl<<endl;

    cout << symmetric_difference.size() << endl;
    for (int i=0; i<symmetric_difference.size(); i++) {
        cout << symmetric_difference[i] << " ";
    }
    cout << endl<<endl;

    return 0;
}
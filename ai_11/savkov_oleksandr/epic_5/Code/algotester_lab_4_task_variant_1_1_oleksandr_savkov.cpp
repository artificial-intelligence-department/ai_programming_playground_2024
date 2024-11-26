#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display(const vector<int>& spys) {
    cout <<  spys.size() << endl;
    for (auto el : spys) {
        cout << el << " ";
    }
    cout << endl;
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

    vector<int> rizn1;
    vector<int> rizn2;
    vector<int> per;
    vector<int> obje;
    vector<int> symriz;

    set_difference(nKil.begin(), nKil.end(), mKil.begin(), mKil.end(), back_inserter(rizn1));
    set_difference(mKil.begin(), mKil.end(), nKil.begin(), nKil.end(), back_inserter(rizn2));
    set_intersection(nKil.begin(), nKil.end(), mKil.begin(), mKil.end(), back_inserter(per));
    set_union(nKil.begin(), nKil.end(), mKil.begin(), mKil.end(), back_inserter(obje));
    set_symmetric_difference(nKil.begin(), nKil.end(), mKil.begin(), mKil.end(), back_inserter(symriz));

    display(rizn1);

    display(rizn2);

    display(per);

    display(obje);

    display(symriz);

    return 0;
}

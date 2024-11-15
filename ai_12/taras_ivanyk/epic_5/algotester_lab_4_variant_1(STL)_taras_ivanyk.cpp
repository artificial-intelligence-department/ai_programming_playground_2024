#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set> // використовується для зберігання унікальних значень без визначеного порядку
using namespace std;
// M - N
vector<int> differenceM_N(const vector<int>& n, const vector<int>& m) {

    vector<int> result;
    set_difference(n.begin(),n.end(),m.begin(), m.end(), back_inserter(result));
    return result;
}
// N - M
vector<int> differenceN_M(const vector<int>& m, const vector<int>& n) {
    
    vector<int> result;
    set_difference(m.begin(),m.end(),n.begin(), n.end(), back_inserter(result));
    return result;
}
// N / M
vector<int> intersection(const vector<int>& n, const vector<int>& m){

    vector<int> result;
    set_intersection(n.begin(),n.end(),m.begin(), m.end(), back_inserter(result));
    return result;
}
// N + M (union)
vector<int> unionN_M(const vector<int>& n, const vector<int>& m){
    vector<int> result;
    set_union(n.begin(),n.end(),m.begin(), m.end(), back_inserter(result));
    return result;
}
// -N - M (simetric difference)
vector<int> simetric_difference(const vector<int>& n, const vector<int>& m){
    vector<int> result;
    set_symmetric_difference(n.begin(),n.end(),m.begin(), m.end(), back_inserter(result));
    return result;
}
int main(){
    int N,M;

    cin >> N;
    vector<int> n(N);
    for (int i = 0; i < N; ++i){
        cin >> n[i];
    }
    cin >> M;
    vector<int> m(M);
    for (int i = 0; i < M; ++i){
        cin >> m[i];
    }
    sort(n.begin(), n.end());
    sort(m.begin(), m.end());
    vector<int> difM_N = differenceM_N(n, m);
    vector<int> difN_M = differenceN_M(m, n);
    vector<int> intersectionN_M = intersection(n, m);
    vector<int> union____NM = unionN_M(n, m);
    vector<int> simDif = simetric_difference(n, m);
    
    cout << difM_N.size() << endl;  //кількість елементів
    for (int num : difM_N) {
        cout << num << " ";  
    }
    cout << endl;
    cout << endl;

// N - M (output)
    cout << difN_M.size() << endl;  
    for (int num : difN_M) {
        cout << num << " ";  
    }
    cout << endl;
    cout << endl;
// N / M (output)
    cout << intersectionN_M.size() << endl;  
    for (int num : intersectionN_M) {
        cout << num << " ";  
    }
    cout << endl;
    cout << endl;
// N + M (output)
    cout << union____NM.size() << endl;  
    for (int num : union____NM) {
        cout << num << " ";  
    }
    cout << endl;
    cout << endl;
// -N - M (output)
    cout << simDif.size() << endl;  
    for (int num : simDif) {
        cout << num << " ";  
    }
    cout << endl;

    return 0;
}



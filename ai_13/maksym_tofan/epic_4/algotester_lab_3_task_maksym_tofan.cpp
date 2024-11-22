#include <iostream>
#include <set>
#include <vector>
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
    
    
    set<int> setA(a.begin(), a.end());
    set<int> setB(b.begin(), b.end());
    set<int> intersectionSet, unionSet;

   
    for (int x : setA) {
        if (setB.count(x)) {
            intersectionSet.insert(x);
        }
    }

   
    unionSet = setA;
    unionSet.insert(setB.begin(), setB.end());

    
    cout << intersectionSet.size() << endl;  
    cout << unionSet.size() << endl;        

    return 0;
}

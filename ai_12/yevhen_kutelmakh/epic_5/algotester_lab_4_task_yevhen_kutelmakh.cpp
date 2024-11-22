#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

//v2 STL

int main() {
    int N, K;
    cin >> N >> K;
    int num;
    set<int> arr;
    for(int i = 0; i < N; i++) {
        cin >> num;
        arr.insert(num);
    }
    vector<int> ar;
    for(int el : arr) 
        ar.push_back(el);
    while(K>ar.size()) {
        K -= ar.size();
    }
    vector<int>::iterator it = ar.begin() + K;
    rotate(ar.begin(), it, ar.end());
    cout << ar.size() << "\n";
    for(int el : ar) 
        cout << el << " ";
    return 0;
}
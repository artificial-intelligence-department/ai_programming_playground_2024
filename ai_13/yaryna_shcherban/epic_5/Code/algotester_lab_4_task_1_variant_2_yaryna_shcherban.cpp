#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    set<int> uniqueElements(a.begin(), a.end());
    vector<int> uniqueVector(uniqueElements.begin(), uniqueElements.end());
    sort(uniqueVector.begin(), uniqueVector.end());

    K = K % uniqueVector.size(); 
    rotate(uniqueVector.begin(), uniqueVector.begin() + K, uniqueVector.end()); 

    cout << uniqueVector.size() << endl; 
    for (int num : uniqueVector) {
        cout << num << " "; 
    }
    cout << endl;
    return 0;
}
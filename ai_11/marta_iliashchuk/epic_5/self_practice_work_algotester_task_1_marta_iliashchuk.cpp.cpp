#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int N, K;
    cin>>N>>K;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin>>a[i];
    }

    set<int> uniqueElements(a.begin(), a.end());
    vector<int> uniqueArray(uniqueElements.begin(), uniqueElements.end());

    sort(uniqueArray.begin(), uniqueArray.end());

    rotate(uniqueArray.begin(), uniqueArray.begin() + K % uniqueArray.size(), uniqueArray.end());

    cout << uniqueArray.size() << endl;
    for (int i = 0; i < uniqueArray.size(); i++) {
        cout<<uniqueArray[i]<<" ";
    }

    return 0;
}
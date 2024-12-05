#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    set<int> unique_set(arr.begin(), arr.end());
    vector<int> unique_arr(unique_set.begin(), unique_set.end());

    vector<int> mod0, mod1, mod2;
    for (int num : unique_arr) {
        if (num % 3 == 0) {
            mod0.push_back(num);
        } else if (num % 3 == 1) {
            mod1.push_back(num);
        } else {
            mod2.push_back(num);
        }
    }

    vector<int> M;

    sort(mod0.begin(), mod0.end());
    M.insert(M.end(), mod0.begin(), mod0.end());
    sort(mod1.rbegin(), mod1.rend()); 
    M.insert(M.end(), mod1.begin(), mod1.end());
    sort(mod2.begin(), mod2.end()); 
    M.insert(M.end(), mod2.begin(), mod2.end());

    M.erase(unique(M.begin(), M.end()), M.end());

    cout << M.size() << endl;
    for (int num : M) {
        cout << num << " ";}
    cout << endl;
    return 0;}

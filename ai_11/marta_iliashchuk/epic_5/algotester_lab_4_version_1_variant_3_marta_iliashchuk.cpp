#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    set<int> unique_elements(a.begin(), a.end());
    vector<int> unique_array(unique_elements.begin(), unique_elements.end());

    vector<int> group0, group1, group2;
    for (int x : unique_array) {
        if (x % 3 == 0)
            group0.push_back(x);
        else if (x % 3 == 1)
            group1.push_back(x);
        else
            group2.push_back(x);
    }

    sort(group0.begin(), group0.end());
    sort(group1.rbegin(), group1.rend()); 
    sort(group2.begin(), group2.end());

    vector<int> result;
    result.insert(result.end(), group0.begin(), group0.end());
    result.insert(result.end(), group1.begin(), group1.end());
    result.insert(result.end(), group2.begin(), group2.end());

    cout << result.size() << endl;
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}

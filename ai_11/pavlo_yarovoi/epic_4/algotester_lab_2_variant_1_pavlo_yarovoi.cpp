#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> r(N);
    for(int i = 0; i < N; i++) {
        cin >> r[i];
    }

    auto minimal = min_element(r.begin(), r.end());
    auto maximal = max_element(r.begin(), r.end());
    
    vector<int> copy_1 = r;
    copy_1.erase(find(copy_1.begin(), copy_1.end(), *maximal));
    
    int diff_1 = *max_element(copy_1.begin(), copy_1.end()) - *min_element(copy_1.begin(), copy_1.end());

    vector<int> copy_2 = r;
    copy_2.erase(find(copy_2.begin(), copy_2.end(), *minimal));
    
    int diff_2 = *max_element(copy_2.begin(), copy_2.end()) - *min_element(copy_2.begin(), copy_2.end());

    cout << min(diff_1, diff_2);
    return 0;
}


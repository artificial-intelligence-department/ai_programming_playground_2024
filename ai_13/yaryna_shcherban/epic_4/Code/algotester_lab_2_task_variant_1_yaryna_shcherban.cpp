#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N;
    cin >> N; 

    vector<int> r(N); 
    for (int i = 0; i < N; ++i) {
        cin >> r[i];
    }

    sort(r.begin(), r.end());

    if (r.size() == 1) {
        cout << 0 << endl;
        return 0;
    }

    int fatigue_1 = r[r.size() - 1] - r[1]; 
    int fatigue_2 = r[r.size() - 2] - r[0]; 

    if (fatigue_1 > fatigue_2) {
        cout << fatigue_2 << endl; 
    } else {
        cout << fatigue_1 << endl; 
    }
    
    return 0;
}
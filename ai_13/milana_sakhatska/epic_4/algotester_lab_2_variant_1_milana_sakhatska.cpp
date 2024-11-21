#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> r(N);
    for (int i = 0; i < N; ++i) {
        cin >> r[i];
    }

    
    if (N <= 2) {
        cout << 0 << endl;
        return 0;
    }

    int minFatigue = INT_MAX; 

    for (int i = 0; i < N; ++i) {
        vector<int> temp = r;
        temp.erase(temp.begin() + i); 

        int maxElement = *max_element(temp.begin(), temp.end()); 
        int minElement = *min_element(temp.begin(), temp.end()); 

        int fatigue = maxElement - minElement; 
        minFatigue = min(minFatigue, fatigue); 
    }

    cout << minFatigue << endl;

    return 0;
}

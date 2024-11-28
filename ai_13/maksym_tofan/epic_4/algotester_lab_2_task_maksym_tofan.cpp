#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int N; 
    cin >> N;

    vector<int> r(N); 
    for (int i = 0; i < N; ++i) {
        cin >> r[i];
    }

    
    int a, b, c;
    cin >> a >> b >> c;

   
    unordered_set<int> toRemove = {a, b, c};
    vector<int> filteredArray;

    
    for (int num : r) {
        if (toRemove.find(num) == toRemove.end()) {
            filteredArray.push_back(num);
        }
    }

    
    vector<int> sums;
    for (size_t i = 0; i + 1 < filteredArray.size(); ++i) {
        sums.push_back(filteredArray[i] + filteredArray[i + 1]);
    }

   
    cout << sums.size() << endl;
    for (int sum : sums) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}

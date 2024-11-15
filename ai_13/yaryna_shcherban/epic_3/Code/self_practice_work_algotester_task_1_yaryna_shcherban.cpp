#include <iostream>
#include <vector>
using namespace std;

int maxSharpenedTeeth(const vector<int>& a, int k) {
    int max_count = 0;
    int current_count = 0; 
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] >= k) {
            current_count++; 
        } else {
            max_count = max(max_count, current_count); 
            current_count = 0; 
        }
    }
    max_count = max(max_count, current_count);
    return max_count;
}

int main() {
    
    int n, k;
    cin >> n;
    cin >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int result = maxSharpenedTeeth(a, k);
    
    cout << result << endl;
    return 0;
}
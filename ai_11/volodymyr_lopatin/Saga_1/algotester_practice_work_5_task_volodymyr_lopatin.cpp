#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 1 || n > 100000) return 0;
    vector<long long> arr;
    vector<long long> even, odd;
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        if (a < 1 || a > 1000000000) return 0;
        arr.push_back(a);
        if (arr[i] % 2 == 0) {
            even.push_back(arr[i]);
        } else {
            odd.push_back(arr[i]);
        }
    }
    if(abs((int)even.size() - (int)odd.size()) > 1) {
        cout << "-1";
        return 0;
    }
    vector<long long> result;
    bool startWithEven = even.size() >= odd.size();
    while(!odd.empty() || !even.empty()) {
        if (!even.empty() && startWithEven) {
            result.push_back(even.back());
            even.pop_back();
        } else if (!odd.empty() && !startWithEven) {
            result.push_back(odd.back());
            odd.pop_back();
        }
        startWithEven = !startWithEven;
    }
    for (long long num : result) {
        cout << num << " ";
    }
    return 0;
}
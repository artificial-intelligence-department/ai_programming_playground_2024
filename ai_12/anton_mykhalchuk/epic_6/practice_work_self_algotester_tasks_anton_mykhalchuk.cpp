#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct PrefixArray {
    vector<int> arr;          
    vector<int> prefixSum;    
    int n;                    


    PrefixArray(int size, const vector<int>& elements) : n(size), arr(elements) {
        prefixSum.resize(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + arr[i];
        }
    }


    int maxPrefixWithSum(int x) {
        int idx = upper_bound(prefixSum.begin(), prefixSum.end(), x) - prefixSum.begin() - 1;
        return idx;
    }


    void addValue(int index, int value) {
        arr[index] += value;
        for (int j = index + 1; j <= n; ++j) {
            prefixSum[j] += value; 
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> elements(n);
    for (int i = 0; i < n; ++i) {
        cin >> elements[i];
    }


    PrefixArray prefixArray(n, elements);


    for (int q = 0; q < m; ++q) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            cout << prefixArray.maxPrefixWithSum(x) << endl;
        } else if (type == 2) {
            int i, d;
            cin >> i >> d;
            prefixArray.addValue(i - 1, d);
        }
    }

    return 0;
}

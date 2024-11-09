#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> teams(k, 1); 
    int ost = n - k; 
  
    if (ost < 0 || ost > 2 * k) {
        cout << "Impossible" << endl;
        return 0;
    }

    for (int i = 0; i < k && ost > 0; ++i) {
        int add = min(2, ost);
        teams[i] += add;
        ost -= add;
    }

    for (int i = 0; i < k; ++i) {
        cout << teams[i] << (i == k - 1 ? "\n" : " ");
    }

    return 0;
}
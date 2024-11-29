#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int> > offices(n);
    for (int i = 0; i < n; i++) {
        int length;
        cin >> length;
        offices[i] = { length, i + 1}; 
    }

    sort(offices.begin(), offices.end());

    for (int i = 0; i < n; i++) {
        cout << offices[i].second << " ";
    }
    cout << endl;

    return 0;
}

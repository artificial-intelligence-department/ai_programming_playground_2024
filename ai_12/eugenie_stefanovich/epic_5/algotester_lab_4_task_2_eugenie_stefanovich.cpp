#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, wid;
    vector<int> base0, base1, base2;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> wid;
        if (wid % 3 == 0)
            base0.push_back(wid);
        else if (wid % 3 == 1 || wid % 3 == -1)
            base1.push_back(wid);
        else if (wid % 3 == 2 || wid % 3 == -2)
            base2.push_back(wid);
    }

    sort(base0.begin(), base0.end());
    sort(base1.begin(), base1.end(), greater<int>());
    sort(base2.begin(), base2.end());

    
    base0.erase(unique(base0.begin(), base0.end()), base0.end());
 
    base1.erase(unique(base1.begin(), base1.end()), base1.end());

    base2.erase(unique(base2.begin(), base2.end()), base2.end());

    cout << base0.size() + base1.size() + base2.size() << endl;

    for (int num : base0) {
        cout << num << " ";
    }
    for (int num : base1) {
        cout << num << " ";
    }
    for (int num : base2) {
        cout << num << " ";
    }

    return 0;
}
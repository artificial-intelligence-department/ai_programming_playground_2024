#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> arrFirst(n);
    for (int i = 0; i < n; i++) cin >> arrFirst[i];

    cin >> m;
    vector<int> arrSecond(m);
    for (int i = 0; i < m; i++) cin >> arrSecond[i];

    vector<int> commonElements;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arrFirst[i] == arrSecond[j]) {
                commonElements.push_back(arrFirst[i]);
                break;
            }
        }
    }

    sort(commonElements.begin(), commonElements.end());
    commonElements.erase(unique(commonElements.begin(), commonElements.end()), commonElements.end());
    int commonCount = commonElements.size();

    vector<int> allElements = arrFirst;
    allElements.insert(allElements.end(), arrSecond.begin(), arrSecond.end());

    sort(allElements.begin(), allElements.end());
    allElements.erase(unique(allElements.begin(), allElements.end()), allElements.end());
    int uniqueCount = allElements.size();

    cout << commonCount << endl;
    cout << uniqueCount << endl;

    return 0;
}

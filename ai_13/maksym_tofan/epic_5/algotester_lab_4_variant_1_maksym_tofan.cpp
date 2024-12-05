#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void displaySortedVector(const vector<int>& vec) {
    cout << vec.size() << endl;
    for (const int& num : vec) {
        cout << num << " ";
    }
    cout << "\n\n";
}

int main() {
    int n, m;
    cin >> n;
    vector<int> setN, setM, uniqueN, commonElements, remainingM, symmetricDifference, unionSet;

    for (int i = 0; i < n; ++i) {
        int element;
        cin >> element;
        setN.push_back(element);
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int element;
        cin >> element;
        setM.push_back(element);
    }

    vector<int> copyM = setM;

    for (int& numN : setN) {
        bool foundInM = false;
        for (int i = 0; i < copyM.size(); ++i) {
            if (numN == copyM[i]) {
                commonElements.push_back(copyM[i]);
                copyM.erase(copyM.begin() + i);
                foundInM = true;
                break;
            }
        }
        if (!foundInM) {
            uniqueN.push_back(numN);
        }
    }

    sort(uniqueN.begin(), uniqueN.end());
    displaySortedVector(uniqueN);

    sort(copyM.begin(), copyM.end());
    displaySortedVector(copyM);

    sort(commonElements.begin(), commonElements.end());
    displaySortedVector(commonElements);

    symmetricDifference.insert(symmetricDifference.end(), uniqueN.begin(), uniqueN.end());
    symmetricDifference.insert(symmetricDifference.end(), copyM.begin(), copyM.end());
    sort(symmetricDifference.begin(), symmetricDifference.end());

    unionSet.insert(unionSet.end(), symmetricDifference.begin(), symmetricDifference.end());
    unionSet.insert(unionSet.end(), commonElements.begin(), commonElements.end());
    sort(unionSet.begin(), unionSet.end());

    displaySortedVector(unionSet);
    displaySortedVector(symmetricDifference);

    return 0;
}

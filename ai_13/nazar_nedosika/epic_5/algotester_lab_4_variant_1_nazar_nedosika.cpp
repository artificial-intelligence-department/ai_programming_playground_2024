#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void displayVector(const vector<int>& vec) {
    cout << vec.size() << endl;
    for (const int& element : vec) cout << element << " ";
    cout << endl;
}
int main() {
    int sizeA, sizeB;
    vector<int> groupA, groupB;
    vector<int> diffA_B, diffB_A, common, allElements, symDiff;

    cin >> sizeA;
    int value;
    for (int i = 0; i < sizeA; i++) {
        cin >> value;
        groupA.push_back(value);
    }
    
    cin >> sizeB;
    for (int i = 0; i < sizeB; i++) {
        cin >> value;
        groupB.push_back(value);
    }

    sort(groupA.begin(), groupA.end());
    sort(groupB.begin(), groupB.end());

    set_difference(groupA.begin(), groupA.end(), groupB.begin(), groupB.end(), back_inserter(diffA_B));
    set_difference(groupB.begin(), groupB.end(), groupA.begin(), groupA.end(), back_inserter(diffB_A));
    set_intersection(groupA.begin(), groupA.end(), groupB.begin(), groupB.end(), back_inserter(common));
    set_union(groupA.begin(), groupA.end(), groupB.begin(), groupB.end(), back_inserter(allElements));
    set_symmetric_difference(groupA.begin(), groupA.end(), groupB.begin(), groupB.end(), back_inserter(symDiff));

    displayVector(diffA_B);
    displayVector(diffB_A);
    displayVector(common);
    displayVector(allElements);
    displayVector(symDiff);

    return 0;
}
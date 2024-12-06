#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void displayResults(const vector<int>& vec) {
    cout << vec.size() << "\n";
    for (auto elem : vec) {
        cout << elem << " ";
    }
    cout << "\n\n";
}

int main() {
    int size1, size2;
    cin >> size1;
    vector<int> list1(size1);
    for (auto& val : list1) {
        cin >> val;
    }

    cin >> size2;
    vector<int> list2(size2);
    for (auto& val : list2) {
        cin >> val;
    }

    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    vector<int> diff1, diff2, common, combined, symDiff;
    set_difference(list1.begin(), list1.end(), list2.begin(), list2.end(), back_inserter(diff1));
    set_difference(list2.begin(), list2.end(), list1.begin(), list1.end(), back_inserter(diff2));
    set_intersection(list1.begin(), list1.end(), list2.begin(), list2.end(), back_inserter(common));
    set_union(list1.begin(), list1.end(), list2.begin(), list2.end(), back_inserter(combined));
    set_symmetric_difference(list1.begin(), list1.end(), list2.begin(), list2.end(), back_inserter(symDiff));

    displayResults(diff1);
    displayResults(diff2);
    displayResults(common);
    displayResults(combined);
    displayResults(symDiff);
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void displayVector(const vector<int>& vec) {
    cout << vec.size() << endl;
    for (const int& element : vec) cout << element << " ";
    cout << endl;
}
vector<int> customDifference(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            result.push_back(a[i]);
            i++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    while (i < a.size()) {
        result.push_back(a[i]);
        i++;
    }
    return result;
}
vector<int> customIntersection(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            i++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            result.push_back(a[i]);
            i++;
            j++;
        }
    }
    return result;
}
vector<int> customUnion(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            result.push_back(a[i]);
            i++;
        } else if (a[i] > b[j]) {
            result.push_back(b[j]);
            j++;
        } else {
            result.push_back(a[i]);
            i++;
            j++;
        }
    }
    while (i < a.size()) {
        result.push_back(a[i]);
        i++;
    }
    while (j < b.size()) {
        result.push_back(b[j]);
        j++;
    }
    return result;
}
vector<int> customSymmetricDifference(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            result.push_back(a[i]);
            i++;
        } else if (a[i] > b[j]) {
            result.push_back(b[j]);
            j++;
        } else {
            i++;
            j++;
        }
    }
    while (i < a.size()) {
        result.push_back(a[i]);
        i++;
    }
    while (j < b.size()) {
        result.push_back(b[j]);
        j++;
    }
    return result;
}
int main() {
    int sizeA, sizeB;
    vector<int> groupA, groupB;
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

    vector<int> diffA_B = customDifference(groupA, groupB);
    vector<int> diffB_A = customDifference(groupB, groupA);
    vector<int> common = customIntersection(groupA, groupB);
    vector<int> allElements = customUnion(groupA, groupB);
    vector<int> symDiff = customSymmetricDifference(groupA, groupB);
    displayVector(diffA_B);
    displayVector(diffB_A);
    displayVector(common);
    displayVector(allElements);
    displayVector(symDiff);

    return 0;
}
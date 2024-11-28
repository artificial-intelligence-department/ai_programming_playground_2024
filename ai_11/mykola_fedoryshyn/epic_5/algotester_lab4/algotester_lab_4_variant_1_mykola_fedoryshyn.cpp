#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display(const vector<int>& vec) {
    cout << vec.size() << '\n';
    for (int num : vec) {
        cout << num << ' ';
    }
    cout << "\n\n";
}


vector<int> Difference(const vector<int>& first, const vector<int>& second) {
    vector<int> diff;
    int i = 0, j = 0;
    while (i < first.size() && j < second.size()) {
        if (first[i] < second[j]) {
            diff.push_back(first[i++]);
        } else if (first[i] > second[j]) {
            ++j;
        } else {
            ++i;
            ++j;
        }
    }
    while (i < first.size()) {
        diff.push_back(first[i++]);
    }
    return diff;
}


vector<int> Intersection(const vector<int>& first, const vector<int>& second) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < first.size() && j < second.size()) {
        if (first[i] == second[j]) {
            result.push_back(first[i]);
            ++i;
            ++j;
        } else if (first[i] < second[j]) {
            ++i;
        } else {
            ++j;
        }
    }
    return result;
}

vector<int> Union(const vector<int>& first, const vector<int>& second) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < first.size() || j < second.size()) {
        if (j == second.size() || (i < first.size() && first[i] < second[j])) {
            result.push_back(first[i++]);
        } else if (i == first.size() || second[j] < first[i]) {
            result.push_back(second[j++]);
        } else {
            result.push_back(first[i]);
            ++i;
            ++j;
        }
    }
    return result;
}

vector<int> SymmetricDifference(const vector<int>& first, const vector<int>& second) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < first.size() || j < second.size()) {
        if (j == second.size() || (i < first.size() && first[i] < second[j])) {
            result.push_back(first[i++]);
        } else if (i == first.size() || second[j] < first[i]) {
            result.push_back(second[j++]);
        } else {
            ++i;
            ++j;
        }
    }
    return result;
}

int main() {
    int size1, size2;
    cin >> size1;
    vector<int> list1(size1);
    for (int &element : list1) {
        cin >> element;
    }

    cin >> size2;
    vector<int> list2(size2);
    for (int &element : list2) {
        cin >> element;
    }

    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());


    vector<int> diff1 = Difference(list1, list2);
    vector<int> diff2 = Difference(list2, list1);
    vector<int> common = Intersection(list1, list2);
    vector<int> combined = Union(list1, list2);
    vector<int> symDiff = SymmetricDifference(list1, list2);


    display(diff1);
    display(diff2);
    display(common);
    display(combined);
    display(symDiff);

    return 0;
}
/*
5
1 2 3 4 5
5
4 5 6 7 8
*/
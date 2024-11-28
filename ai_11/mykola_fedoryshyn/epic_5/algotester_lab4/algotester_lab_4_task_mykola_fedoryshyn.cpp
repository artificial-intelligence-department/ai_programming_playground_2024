#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display(const vector<int>& vec) {
    int s = vec.size();
    cout << s << '\n';
    for (int i = 0; i<s; i++) {
        cout << vec[i] << ' ';
    }
    cout << "\n\n";
}

int main() {
    vector<int> diff1, diff2, common, combined, symDiff;
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


    set_difference(list1.begin(), list1.end(), list2.begin(), list2.end(), back_inserter(diff1));
    set_difference(list2.begin(), list2.end(), list1.begin(), list1.end(), back_inserter(diff2));
    set_intersection(list1.begin(), list1.end(), list2.begin(), list2.end(), back_inserter(common));
    set_union(list1.begin(), list1.end(), list2.begin(), list2.end(), back_inserter(combined));
    set_symmetric_difference(list1.begin(), list1.end(), list2.begin(), list2.end(), back_inserter(symDiff));

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

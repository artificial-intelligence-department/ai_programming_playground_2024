#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

void output(vector<int> arr)
{
    cout << arr.size() << endl;
    sort(arr.begin(), arr.end());
    for (int el : arr)
        cout << el << " ";
    cout << "\n\n";
}

int main()
{
    int s;
    cin >> s;
    vector<int> N(s);
    while (s--)
        cin >> N[s];
    cin >> s;
    vector<int> M(s), L1, L2, L3, L4, L5;
    while (s--)
        cin >> M[s];

    sort(N.begin(), N.end());
    sort(M.begin(), M.end());

    // ця хрінь вимагає відсортованості для повністю коректної роботи
    set_difference(N.begin(), N.end(), M.begin(), M.end(), back_inserter(L1));
    set_difference(M.begin(), M.end(), N.begin(), N.end(), back_inserter(L2));
    set_intersection(M.begin(), M.end(), N.begin(), N.end(), back_inserter(L3));
    set_union(M.begin(), M.end(), N.begin(), N.end(), back_inserter(L4));
    set_symmetric_difference(M.begin(), M.end(), N.begin(), N.end(), back_inserter(L5));

    output(L1);
    output(L2);
    output(L3);
    output(L4);
    output(L5);

    return 0;
}
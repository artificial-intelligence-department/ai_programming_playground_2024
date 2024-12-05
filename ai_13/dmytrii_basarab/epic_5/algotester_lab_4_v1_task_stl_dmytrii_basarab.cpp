#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void output(vector<int> &a)
{
    sort(a.begin(), a.end());
    cout << a.size() << endl;
    for (int element : a) {
        cout << element << " ";
    }
    cout << endl;
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> arr1(n);

    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    vector<int> dif1;
    set_difference(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(dif1));
    cout << "Різниця n / m: ";
    output(dif1);

    vector<int> dif2;
    set_difference(arr2.begin(), arr2.end(), arr1.begin(), arr1.end(), back_inserter(dif2));
    cout << "Різниця m / n: ";
    output(dif2);

    vector<int> inter;
    set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(inter));
    cout << "перетин: ";
    output(inter);

    vector<int> un;
    set_union(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(un));
    cout << "обєднання: ";
    output(un);

    vector<int> sdif;
    set_symmetric_difference(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(sdif));
    cout << "симетрична різниця: ";
    output(sdif);

    return 0;
}
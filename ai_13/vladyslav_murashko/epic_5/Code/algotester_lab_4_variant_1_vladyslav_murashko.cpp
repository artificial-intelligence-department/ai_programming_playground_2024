#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArr(const vector<int> &arr)
{
    cout << "\n\n"
         << arr.size() << endl;
    for (auto &el : arr)
    {
        cout << el << " ";
    }
}

int main()
{
    int N, M;
    cin >> N;
    vector<int> set1(N);
    for (auto &el : set1)
    {
        cin >> el;
    }
    cin >> M;
    vector<int> set2(M);
    for (auto &el : set2)
    {
        cin >> el;
    }

    vector<int> diff1;
    vector<int> diff2;
    vector<int> inter;
    vector<int> uni;
    vector<int> symDiff;

    sort(set1.begin(),set1.end());
    sort(set2.begin(),set2.end());

    set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(diff1));
    set_difference(set2.begin(), set2.end(), set1.begin(), set1.end(), std::back_inserter(diff2));
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(inter));
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(uni));
    set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(symDiff));

    printArr(diff1);
    printArr(diff2);
    printArr(inter);
    printArr(uni);
    printArr(symDiff);

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N;
    int num;
    vector<int> set1;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        set1.push_back(num);
    }
    cin >> M;
    vector<int> set2;
    for (int i = 0; i < M; i++)
    {
        cin >> num;
        set2.push_back(num);
    }

    cout << endl;
    sort(set1.begin(), set1.end());
    sort(set2.begin(), set2.end());
    vector<int> dif1;
    set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(dif1, dif1.end()));
    cout << dif1.size() << endl;
    for (int e : dif1)
    {
        cout << e << " ";
    }
    cout << endl;
    vector<int> dif2;
    set_difference(set2.begin(), set2.end(), set1.begin(), set1.end(), inserter(dif2, dif2.end()));
    cout << dif2.size() << endl;
    for (int e : dif2)
    {
        cout << e << " ";
    }
    cout << endl;
    vector<int> inter;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(inter, inter.end()));
    cout << inter.size() << endl;
    for (int e : inter)
    {
        cout << e << " ";
    }
    cout << endl;
    vector<int> un;
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(un, un.end()));
    cout << un.size() << endl;
    for (int e : un)
    {
        cout << e << " ";
    }
    cout << endl;
    vector<int> sym;
    set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(sym, sym.end()));
    cout << sym.size() << endl;
    for (int e : sym)
    {
        cout << e << " ";
    }
    cout << endl;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void output(vector<int> &a)
{
    sort(a.begin(), a.end());
    cout << a.size() << endl;
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
}

bool in_array(int x, vector<int> &r)
{
    for (int i = 0; i < r.size(); i++)
        if (r[i] == x)
        {
            r[i] = -1;
            return true;
        }
    return false;
}

vector<int> difference(vector<int> a, vector<int> b)
{
    vector<int> c;
    for (int i = 0; i < a.size(); i++)
        if (!in_array(a[i], b))
            c.push_back(a[i]);

    return c;
}

vector<int> intersection(vector<int> a, vector<int> b)
{
    vector<int> c;
    for (int i = 0; i < a.size(); i++)
        if (in_array(a[i], b))
            c.push_back(a[i]);

    return c;
}

vector<int> union_arr(vector<int> a, vector<int> b)
{
    vector<int> c = a;
    for (int x : b)
        if (!in_array(x, a))
            c.push_back(x);
    return c;
}

vector<int> s_difference(vector<int> a, vector<int> b)
{
    vector<int> x = union_arr(a, b);
    vector<int> y = intersection(a, b);

    vector<int> c = difference(x, y);
    return c;
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

    vector<int> dif1 = difference(arr1, arr2);
    output(dif1);

    vector<int> dif2 = difference(arr2, arr1);
    output(dif2);

    vector<int> inter = intersection(arr1, arr2);
    output(inter);

    vector<int> un = union_arr(arr1, arr2);
    output(un);

    vector<int> sdif = s_difference(arr1, arr2);
    output(sdif);

    return 0;
}
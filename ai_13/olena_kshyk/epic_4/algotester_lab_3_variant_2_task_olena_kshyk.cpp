#include <iostream>
#include <vector>
using namespace std;

bool in_array(vector<int> v, int x)
{
    for (int i = 0; i < v.size(); i++)
        if (v[i] == x)
            return true;
    return false;
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int k = 0;
    for (int i = 0; i < n; i++)
        if (in_array(b, a[i]))
            k++;
    cout << k << endl;
    cout << n + m - k; 

    return 0;
}
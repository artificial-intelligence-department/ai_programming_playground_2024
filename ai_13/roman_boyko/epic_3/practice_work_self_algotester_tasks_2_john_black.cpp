#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, s;
    int res = 0, k = 0;
    cin >> n >> s;
    int elect[n] = {};
    int re_elect[n] = {};
    for (int i = 0; i < n; i++)
    {
        cin >> elect[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> re_elect[i];
    }
    for (int j = 0; j < n; j++)
    {
        k += fabs(elect[j] - re_elect[j]);
    }
    res = s - k;
    cout << res;
}
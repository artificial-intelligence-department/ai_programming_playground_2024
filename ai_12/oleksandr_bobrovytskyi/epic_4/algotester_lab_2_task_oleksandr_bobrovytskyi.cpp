#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, temp = 0;
    int N = 0;
    cin >> N;

    if(N > 10e4 || N < 0)
    {
        return 0;
    }

    vector<int> v1(N);

    for(int i = 0; i < v1.size(); i++)
    {
        cin >> v1[i];
        if(v1[i] > 10e4 || v1[i] < 0)
        {
            return 0;
        }
    }

    cin >> a >> b >> c;

    if(a > 10e4 || a < 0 || b > 10e4 || b < 0 || c > 10e4 || c < 0)
    {
        return 0;
    }

    for(int i = 0; i < v1.size(); i++)
    {
        if(v1[i] == a || v1[i] == b || v1[i] == c)
        {
            v1.erase(v1.begin() + i - temp);
            i--;
        }
    }

    if(v1.size() == 0)
    {
        cout << "0";
        return 0;
    }

    cout << v1.size() - 1 << endl;

    for(int i = 0; i < (v1.size() - 1); i++)
    {
        cout << v1[i] + v1[i + 1] << " ";
    }

    return 0;
}
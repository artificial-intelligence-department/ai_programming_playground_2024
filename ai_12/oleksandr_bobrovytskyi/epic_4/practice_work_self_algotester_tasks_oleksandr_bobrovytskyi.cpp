#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, sum = 0;

    cin >> n;

    if(n > 10e3 || n < 1)
    {
        return 1;
    }

    vector<int> v1(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v1[i];
        if(v1[i] > 10 || v1[i] < -10)
        {
            return 1;
        }
    }

    for(int i = 0; i < n; i++)
    {
        sum += v1[i] * (n - i);
    } 
    
    cout << sum;

    return 0;
}
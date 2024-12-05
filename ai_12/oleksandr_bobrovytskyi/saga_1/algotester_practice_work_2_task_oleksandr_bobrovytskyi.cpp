#include <bits/stdc++.h>

using namespace std;

int main()
{   
    int n, m;
    string name;
    unordered_set<string> drinks;

    cin >> n >> m;

    if(n < 0 || n > 777 || m < 0 || m > 777)
    {
        return 1;
    }

    for(int i = 0; i < n; i++)
    {
        cin >> name;
        if(name.size() > 7 || name.size() < 1)
        {
            return 1;
        }
        drinks.insert(name);
    }

    for(int i = 0; i < m; i++)
    {
        cin >> name;
        if(name.size() > 7 || name.size() < 1)
        {
            return 1;
        }

        drinks.insert(name);
    }

    cout << drinks.size() << endl;

    return 0;
}
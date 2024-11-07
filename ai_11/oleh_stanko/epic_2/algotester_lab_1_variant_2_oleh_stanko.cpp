#include <iostream>

using namespace std;

int main()
{
    long long h[4];
    long long d[4];
    bool overturn=0;
    for (int i = 0; i < 4; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> d[i];
        if (h[i] < d[i])
        {
            cout << "ERROR";
            return 0;
        }       
    }
    for (int i = 0; i < 4; i++)
    {
        h[i]-=d[i];      
        for (int j = 0; j < 4; j++)
        {
            if (h[j] >= h[i] * 2)
            {
                overturn=1;
            }
        }
    }  
    if (overturn)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
    return 0;
}

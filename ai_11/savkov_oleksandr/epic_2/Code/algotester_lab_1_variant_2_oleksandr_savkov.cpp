
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    
    long long h[4];
    long long min_h = 0;
    long long max_h = 0;
    bool result = true;
    
    for (int i = 0; i < 4; i++)
    {
        cin >> h[i];
        min_h = min(h[i], min_h);
        max_h = max(h[i], max_h);
    }
    
    for (int i = 0; i < 4; i++)
    {
        long long d;
        cin >> d;
        if (d > h[i])
        {
            cout << "ERROR" << endl;
            return 0;
        }
        h[i] = h[i] - d;
        min_h = *min_element(h, h + 4);
        max_h = *max_element(h, h + 4);

        if (max_h >= 2 * min_h)
            result = false;
    }
    

    if ((result == false) || (!(h[0] == h[1] && h[1] == h[2] && h[2] == h[3])))
        {
            cout << "NO" << endl;
            return 0;
        }
    cout << "YES" << endl;
    return 0;
}
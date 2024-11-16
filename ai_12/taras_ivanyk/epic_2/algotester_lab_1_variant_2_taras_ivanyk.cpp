#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long h1,h2,h3,h4;
    cin >> h1 >> h2 >> h3 >> h4;

    long long d1,d2,d3,d4;
    cin >> d1 >> d2 >> d3>> d4;

    long long legs[4] = {h1,h2,h3,h4};
    long long cuts[4] = {d1,d2,d3,d4};

    for (int i = 0; i < 4; ++i )
    {
        if (legs[i] < cuts[i])
        {
            cout << "ERROR" << endl;
            return 0;
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        legs[i] -= cuts[i];

        long long min = *min_element(legs, legs + 4);
        long long max = *max_element(legs, legs + 4);

        if (max >= 2*min)
        {
            cout << "NO";
            return 0;
        }
    }
    long long final_min = *min_element(legs, legs + 4);
    if (final_min > 0){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}
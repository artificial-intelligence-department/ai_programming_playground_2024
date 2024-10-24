#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    vector<long long> leg(4);
    cin >> leg[0] >> leg[1] >> leg[2] >> leg[3];

    long long minHight, maxHight;

    string answ[] = {"YES", "NO", "ERROR"};

    int cond = 0;

    for (size_t i = 0; i < 4; i++)
    {
        long long l;
        cin >> l;

        leg[i] -= l;
        
        if (leg[i] >= 0)
        {
            maxHight = *max_element(leg.begin(), leg.end());
            minHight = *min_element(leg.begin(), leg.end());

            if (maxHight >= minHight * 2 || minHight == 0)
            {
                cond = 1;
            }
        }
        else
        {
            cond = 2;
            break;
        }
    }

    cout << answ[cond];

    return 0;
}
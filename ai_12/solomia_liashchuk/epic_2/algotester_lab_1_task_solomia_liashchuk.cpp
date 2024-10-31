#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    vector<long long> leg(4);
    
    cin >> leg[0] >> leg[1] >> leg[2] >> leg[3];
    
    long long minH, maxH;
    string answ[] = {"YES", "NO", "ERROR"};
    int cond = 0;

    for (size_t i = 0; i < 4; i++) 
    {
        long long L;
        cin >> L;
        leg[i] -= L;
        if (leg[i] >= 0) 
        {
            long long maxH = *max_element(leg.begin(), leg.end());
            long long minH = *min_element(leg.begin(), leg.end());

            if (maxH >= 2 * minH || minH == 0) 
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

    cout << answ[cond] << endl;  
    return 0;
}

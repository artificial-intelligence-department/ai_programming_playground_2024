#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<long long> h(4);
    cin >> h[0] >> h[1] >> h[2] >> h[3];

    string answer[] = {"YES", "NO", "ERROR"};
    int index = 0;

    long long min_leg, max_leg;

    for (size_t i = 0; i < 4; i++)
    {
        long long d;
        cin >> d;

        h[i] -= d;
        
        if (h[i] >= 0)
        {
            max_leg = *max_element(h.begin(), h.end());
            min_leg = *min_element(h.begin(), h.end());

            if (max_leg >= min_leg*2 || min_leg == 0)
            {
                index = 1;
            }
        }
        else
        {
            index = 2;
            break;
        }
    }

    cout << answer[index];
    return 0;
}
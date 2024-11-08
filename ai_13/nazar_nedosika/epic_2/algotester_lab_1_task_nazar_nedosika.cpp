#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    long long h_max, h_min, d;

    vector<long long> h(4);

    string answer = "YES";

     for (int i = 0; i < 4; i++)
    {
        cin >> h[i];
    }

    for (size_t i = 0; i < 4; i++){
        
        cin >> d;
        h[i] -= d;

        if ( h[i] >= 0)
        {
            h_max = *max_element(h.begin(), h.end());
            h_min = *min_element(h.begin(), h.end());

            if ( h_max >= h_min * 2 || h_min == 0 ) 
            {
                answer = "NO";
            }  
        }
        else 
        {
            answer = "ERROR";
            break;
        }
    }
    
    cout << answer;
    return 0;
}
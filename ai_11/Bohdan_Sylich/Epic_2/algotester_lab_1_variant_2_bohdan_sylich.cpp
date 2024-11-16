#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector <long long> h(4);
    long long d;
    int c = 0;
    cin >> h[0] >> h[1] >> h[2] >> h[3];
    for (int i = 0; i < 4; i++){
        cin >> d;
        h[i] -= d;
        if (h[i] >= 0)
        {
            long long max_vel = *max_element(h.begin(), h.end());
            long long min_vel = *min_element(h.begin(), h.end());
            if (max_vel >= min_vel*2 || min_vel == 0){
                 c = 1;
            }
        }
        else
        {
            c = 2;
            break;
        }
    }
    switch (c)
    {
    case 1:
        cout << "NO";
        break;
    case 2:
        cout << "ERROR";
        break;
    case 0:
        cout << "YES";
        break;
    default:
        break;
    }
    return 0;

} 
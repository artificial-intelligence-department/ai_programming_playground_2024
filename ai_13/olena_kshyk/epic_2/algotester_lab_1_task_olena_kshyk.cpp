#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector <unsigned long long> h(4);
    cin >> h[0] >> h[1] >> h[2] >> h[3];
    bool error = false;
    bool r = false;
    unsigned long long max, min;

    for (int i=0; i<4; i++){
        unsigned long long d;
        cin >> d;
        if (d > h[i]){
            error = true;
            break;
        } else{
            h[i] = h[i] - d;
        }
        max = *max_element(h.begin(), h.end());
        min = *min_element(h.begin(), h.end());
        if (max >= 2*min){
            r = true;
        }
    }

    if (error){
        cout << "ERROR";
    } else if (!r && min)
    {
        cout << "YES";
    } else{
        cout << "NO";
    }

    return 0;
}
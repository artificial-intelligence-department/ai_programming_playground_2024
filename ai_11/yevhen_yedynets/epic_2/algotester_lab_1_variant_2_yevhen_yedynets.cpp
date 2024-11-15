#include<iostream>
using namespace std;

int main(){
    long long h[4], d[4];
    bool overturned = false;


    cin >> h[0] >> h[1] >> h[2] >> h[3];
    cin >> d[0] >> d[1] >> d[2] >> d[3];


    long long h_max = h[0];
    long long h_min = h[0];

    for (short i = 0; i < 4; i++){
        h[i] -= d[i];
        if (h[i] < 0){
            cout << "ERROR";
            return 0;
        }
        
        h_max = h[0];
        h_min = h[0];

        for (short j = 0; j < 4; j++){
            if (h[j] > h_max)
                h_max = h[j];
            if (h[j] < h_min)
                h_min = h[j];
        }

        if (h_max >= 2 * h_min){
            overturned = true;
        }
    }


    if (overturned == true || h_min == 0){
        cout << "NO";
    }
    else
        cout << "YES";


    return 0;
}

#include <iostream>
#include <climits> 

using namespace std;

int main() {
    int N, M;
    cin >> N;

    if(N <= 1){
        cout << 0;
        return 0;
    }
    int r[N];

    for (int i = 0; i < N; ++i) {
       cin >> r[i];
    }

    int max1 = INT_MIN, max2 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int i = 0; i < N; ++i){
        if(r[i] < min1){
            min2 =min1;
            min1 = r[i];
        }else if (r[i] < min2){
            min2 = r[i];
        }
        if(r[i] > max1){
            max2 = max1;
            max1 = r[i];
        } else if(r[i] > max2){
            max2 = r[i];
        }
    }
    
    if(max1 - min2 <= max2 - min1){
        M = max1 - min2;
    }else {
        M = max2 - min1;
    }
    cout <<  M;

    return 0;
}


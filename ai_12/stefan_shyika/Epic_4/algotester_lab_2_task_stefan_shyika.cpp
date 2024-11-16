#include <iostream>
#include <climits>

using namespace std;

int main(){
    int N, m;

    cin >> N;
    if(N <= 2){
        cout << 0;
        return 0;
    }
    int r[N];

    for(int i = 0; i < N; i++){
        cin >> r[i];
    }


    int min1 = INT_MAX, min2 = INT_MAX;
    int max1 = INT_MIN, max2 = INT_MIN;

    for(int i = 0; i < N; i++){
        if (r[i] < min1) {
            min2 = min1;
            min1 = r[i];
        } else if (r[i] < min2) {
            min2 = r[i];
        }

        if (r[i] > max1) {
            max2 = max1;
            max1 = r[i];
        } else if (r[i] > max2) {
            max2 = r[i];
        }
    }

    if(max1 - min2 <= max2 - min1){
        m = max1 - min2;
    }else{
        m = max2 - min1;
    }

    cout << m;
}
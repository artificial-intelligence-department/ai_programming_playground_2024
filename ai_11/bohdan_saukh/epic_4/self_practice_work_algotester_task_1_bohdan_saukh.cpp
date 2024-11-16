#include <iostream>

using namespace std;

int main(){
    int n;
    
    cin >> n;
    
    int r[n];
    
    int min = 2147483645;
    int minp = 2147483645;
    
    int max = -2147483645;
    int maxp = -2147483645;
    
    if (n > 1){
        for(int i = 0; i < n; i++){
            cin >> r[i];
            if (r[i] >= max) {
                maxp = max;
                max = r[i];
            } else if (r[i] > maxp && r[i] < max) {
                maxp = r[i];
            }
            if (r[i] <= min) {
                minp = min;
                min = r[i];
            } else if (r[i] < minp && r[i] > min) {
                minp = r[i];
            }
        }
        if ((maxp - min) <= (max - minp)){
            cout << maxp - min;
        }else{
            cout << max - minp;
        }
    }else{
        cin >> r[0];
        cout << "0";
    }    
    return 0;
}


#include <iostream>
#include <algorithm> 
using namespace std;

int main(){
    long h[4];
    long d[4];
    bool perevernut = false;
    for(int i=0; i<4; i++){
        cin >> h[i];
    }
    for(int i=0; i<4; i++){
        cin >> d[i];
        if (d[i]>h[i]){
            cout << "ERROR";
            return 0;
        }
        h[i] -= d[i];
        long* h_max = max_element(h, h + 4);
        long* h_min = min_element(h, h + 4);

        if (*h_max >= 2*(*h_min)){
            perevernut = true;
        }
    }
    if(!perevernut && *min_element(h, h + 4) != 0){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
